#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#ifndef TEST

int main(int argc, char *argv[])
{
	if (1 == argc) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (0);
	}
	for (int i = 1; i < argc; i++) {
		int l = strlen(argv[i]);
		for (int j = 0; j < l; j++) {
			cout << (char)toupper(argv[i][j]);
		}
	}
	cout << endl;
}

#else // =======================================================================

#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <cassert>

#define DEBUG

#define SZ 3

using std::ifstream;
using std::string;
using std::stringstream;

class TestCase {
	public:
	int m_src_sz;
	string *m_src_strs;
	string m_exp;

	TestCase(int p_src_sz, const string p_src_strs[], string p_exp)
		: m_src_sz(p_src_sz), m_exp(p_exp) {
		try {
			m_src_strs = new string[p_src_sz];
		} catch (const std::bad_alloc &e) {
			cerr << "allocation failed" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < p_src_sz; i ++) {
			m_src_strs[i] = p_src_strs[i];
		}
	}

	~TestCase() {
		delete[] m_src_strs;
	}
};

int main(void) {
	const string test1[] = {"shhhhh... I think the students are asleep..."};
	const string test2[] = {"Damnit", " ! ", "Sorry students, I thought this thing was off."};
	const string test3[] = {};
	TestCase tests[SZ] = {
		TestCase(1, test1, "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...\n")
		, TestCase(3, test2, "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.\n")
		, TestCase(0, test3, "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n")
	};

	stringstream ss;
	ifstream ifs;
	for (int i = 0; i < SZ; i++) {
		#ifdef DEBUG
		cout << "#" << i << endl;
		#endif
		ss << "rm -f out.txt err.txt && bash -c 'valgrind --leak-check=full --show-leak-kinds=all ./megaphone";
		for (int j = 0; j < tests[i].m_src_sz; j++) {
			ss << " \"" << tests[i].m_src_strs[j] << "\"";
		}
		ss << "' 1> out.txt 2> err.txt";
		assert(0 == system(ss.str().c_str()));
		ss.str("");

		ifs.open("out.txt");
		assert(ifs.is_open());
		ss << ifs.rdbuf();
		ifs.close();
		#ifdef DEBUG
		if (0 != ss.str().compare(tests[i].m_exp))
			cout << "expected {" << tests[i].m_exp << "}" << endl << "got {" << ss.str() << "}" << endl;
		#endif
		assert(0 == ss.str().compare(tests[i].m_exp));
		ss.str("");
		
		ifs.open("err.txt");
		ss << ifs.rdbuf();
		ifs.close();
		assert(string::npos != ss.str().find("ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)"));
		ss.str("");
	}
	return (0);
}

#endif