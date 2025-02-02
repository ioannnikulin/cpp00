#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>

#include "PhoneBook.hpp"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::streambuf;
using std::string;
using std::stringstream;

#define DEBUG

#define SZ 1

class TestCase {
public:
	int m_inputs_qtty;
	string *m_inputs;
	string m_exp;

	TestCase(int inputs_qtty, const string inputs[], const string exp)
		: m_inputs_qtty(inputs_qtty), m_exp(exp) {
		try {
			m_inputs = new string[inputs_qtty];
		} catch (const std::bad_alloc &e) {
			cerr << "allocation failed" << endl;
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < inputs_qtty; i ++) {
			m_inputs[i] = inputs[i];
		}
	}

	~TestCase() {
		delete[] m_inputs;
	}
};

int main(void) {
	const string test1[] = {
		"SEARCH", "0", "qwe", ""
		, "ADD", "andrew", "andrewsson", "triple a", "88005553535", "he is cool"
		, "SEARCH", "1", "", "-2", "qwe", "0"
		, "ADD", "bjorn", "", "", "bjornsson", "bibi", "+31415926", "he is even cooler"
		, "ADD", "bjorn", "bjornsson", "bibi", "", "+31415926", "he is even cooler"
		, "SEARCH", "1"
		, "EXIT"
	};
	const string exp1 = "";
	TestCase tests[SZ] = {
		TestCase(33, test1, exp1)
	};

	stringstream ss;
	for (int i = 0; i < SZ; i++) {
		#ifdef DEBUG
		cout << "#" << i << endl;
		#endif

		stringstream in;
		stringstream out;
		for (int j = 0; j < tests[i].m_inputs_qtty; j ++) {
			in << tests[i].m_inputs[j] << endl;
		}
		streambuf *orig_cin = cin.rdbuf(in.rdbuf());
		streambuf *orig_cout = cout.rdbuf(out.rdbuf());

		PhoneBook book;
		book.operate();
		
		cin.rdbuf(orig_cin);
		cout.rdbuf(orig_cout);
		string act = out.str();
		#ifdef DEBUG
		if (0 != act.compare(tests[i].m_exp)) {
			cout << "expected: [" << tests[i].m_exp << "], actual [" << act << "]";
		}
		#endif
		assert(0 == act.compare(tests[i].m_exp));
	}
	return (0);
}