#include "PhoneBook.hpp"

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