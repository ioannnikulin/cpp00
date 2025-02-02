#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string.h>
# include <stdlib.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

class Contact {
private:
	string m_f_name;
	string m_l_name;
	string m_nick_name;
	string m_phone_no;
	string m_secret;

public:
	Contact();
	Contact(
		string f_name
		, string l_name
		, string nick_name
		, string phone_no
		, string secret
	);
	Contact(const Contact &other);
	Contact &operator=(const Contact &other);
	Contact(Contact &&other) noexcept;
	Contact &operator=(Contact &&other) noexcept;
	~Contact();

	
	string toString(int mode = FULL);
};

#endif