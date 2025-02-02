#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <stdlib.h>
# include <string.h>

# include "Contact.hpp"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

# define MAX_CONTACTS 8

class Contact;

class PhoneBook {
private:
	int	m_curContact;
	int m_addedContacts;
	Contact	m_contacts[MAX_CONTACTS];

	PhoneBook(const PhoneBook &other);
	PhoneBook &operator=(const PhoneBook &other);

	int addInteractive();
	int search();
public:
	PhoneBook();
	~PhoneBook();

	int operate();
};

#endif