#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string.h>
# include <stdlib.h>

# include "Contact.hpp"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

class Contact;

class PhoneBook {
private:
	int	cur_contact;
	Contact	contacts[8];

public:
	PhoneBook();
	PhoneBook(const PhoneBook &other);
	PhoneBook &operator=(const PhoneBook &other);
	PhoneBook(const PhoneBook &&other) noexcept;
	PhoneBook &operator=(const PhoneBook &&other) noexcept;

	int add_interactive();
	int search();
}

#endif