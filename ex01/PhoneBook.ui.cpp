#include <iomanip>
#include <limits>
#include <sstream>

#include "PhoneBook.hpp"

using std::setw;
using std::right;

int PhoneBook::addInteractive() {
	m_contacts[m_curContact] = Contact(cin, cout);
	m_curContact = (m_curContact + 1) % MAX_CONTACTS;
	m_addedContacts = std::min(m_addedContacts + 1, MAX_CONTACTS);
	return (0);
}

int PhoneBook::search() {
	cout 
		<< setw(10) << right << "index" << "|"
		<< setw(10) << right << "first name" << "|"
		<< setw(10) << right << "last name" << "|"
		<< setw(10) << right << "nickname" << "|"
		<< endl;
	for (int i = 0; i < m_addedContacts; i ++) {
		cout << setw(10) << right << i << "|" << m_contacts[i].toString(Contact::FLN_PIPE_10) << NEWLINE;
	}
	if (0 == m_addedContacts)
		return (0);
	cout << "Please select an entry:" << NEWLINE << "> ";
	int choice = 0;
	while (true) {
		string choice_s;
		std::getline(cin, choice_s);
		std::istringstream iss(choice_s);
		if (!(iss >> choice) || choice < 0 || choice >= m_addedContacts) {
			cout << "Entry not found, please try again" << NEWLINE <<  "> ";
			continue ;
		}
		break ;
	}
	cout << m_contacts[choice].toString(Contact::FLNPS_SEP_LINES);
	return (0);
}

int PhoneBook::operate() {
	while (true) {
		string choice;
		while (choice.empty()) {
			cout << endl << "Enter your command:" << NEWLINE << "> ";
			std::getline(cin, choice);
		}
		if (0 == choice.compare("ADD")) {
			if (0 != addInteractive()) {
				return (1);
			}
		} else if (0 == choice.compare("SEARCH")) {
			if (0 != search()) {
				return (2);
			}
		} else if (0 == choice.compare("EXIT")) {
			break;
		}
	}
	return (0);
}