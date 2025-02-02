#include <sstream>
#include <iomanip>
#include "Contact.hpp"

using std::move;
using std::stringstream;
using std::setw;

Contact::Contact()
	: m_f_name("")
	, m_l_name("")
	, m_nick_name("")
	, m_phone_no("")
	, m_secret("")
{}

Contact::Contact(
	string f_name
	, string l_name
	, string nick_name
	, string phone_no
	, string secret
)
	: m_f_name(f_name)
	, m_l_name(l_name)
	, m_nick_name(nick_name)
	, m_phone_no(phone_no)
	, m_secret(secret)
{}

Contact::Contact(const Contact &other)
	: m_f_name(other.m_f_name)
	, m_l_name(other.m_l_name)
	, m_nick_name(other.m_nick_name)
	, m_phone_no(other.m_phone_no)
	, m_secret(other.m_secret)
{}

Contact &Contact::operator=(const Contact &other) {
	if (this != &other) {
		m_f_name = other.m_f_name;
		m_l_name = other.m_l_name;
		m_nick_name = other.m_nick_name;
		m_phone_no = other.m_phone_no;
		m_secret = other.m_secret;
	}
	return (*this);
}

Contact::Contact(Contact &&other) noexcept
	: m_f_name(move(other.m_f_name))
	, m_l_name(move(other.m_l_name))
	, m_nick_name(move(other.m_nick_name))
	, m_phone_no(move(other.m_phone_no))
	, m_secret(move(other.m_secret))
{}

Contact &Contact::operator=(Contact &&other) noexcept {
	if (this != &other) {
		m_f_name = move(other.m_f_name);
		m_l_name = move(other.m_l_name);
		m_nick_name = move(other.m_nick_name);
		m_phone_no = move(other.m_phone_no);
		m_secret = move(other.m_secret);
	}
	return (*this);
}

Contact::~Contact() {
}

string Contact::toString() {
	stringstream ss;
	ss 
		<< setw(10) << m_f_name << "|" 
		<< setw(10) << m_l_name << "|"
	;
	return (ss.str());
}