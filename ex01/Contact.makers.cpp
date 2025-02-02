#include "Contact.hpp"

using std::runtime_error;

Contact::Contact()
	: m_fName("")
	, m_lName("")
	, m_nickName("")
	, m_phoneNo("")
	, m_secret("")
{}

Contact::Contact(
	string fName
	, string lName
	, string nickName
	, string phoneNo
	, string secret
)
	: m_fName(fName)
	, m_lName(lName)
	, m_nickName(nickName)
	, m_phoneNo(phoneNo)
	, m_secret(secret)
{}

Contact::Contact(const Contact &other)
	: m_fName(other.m_fName)
	, m_lName(other.m_lName)
	, m_nickName(other.m_nickName)
	, m_phoneNo(other.m_phoneNo)
	, m_secret(other.m_secret)
{}

Contact &Contact::operator=(const Contact &other) {
	if (this != &other) {
		m_fName = other.m_fName;
		m_lName = other.m_lName;
		m_nickName = other.m_nickName;
		m_phoneNo = other.m_phoneNo;
		m_secret = other.m_secret;
	}
	return (*this);
}

Contact::~Contact() {
}

const Contact::ToStringMode Contact::FLN_PIPE_10(Contact::ToStringMode::F_NAME | Contact::ToStringMode::L_NAME | Contact::ToStringMode::NICK_NAME, 10, ".", "|");

const Contact::ToStringMode Contact::FLNPS_SEP_LINES(Contact::ToStringMode::F_NAME | Contact::ToStringMode::L_NAME | Contact::ToStringMode::NICK_NAME | Contact::ToStringMode::PHONE_NO | Contact::ToStringMode::SECRET, 0, "", NEWLINE);

int getField(string &field, const string &prompt, bool allowEmpty, istream &ifs, ostream &ofs) {
    while (true) {
        ofs << prompt << NEWLINE << "> ";
        std::getline(ifs, field);
        if (!allowEmpty && field.empty()) {
            ofs << "Field cannot be empty" << endl;
            continue;
        }
        break;
    }
    return (0);
}

Contact::Contact(istream &ifs, ostream &ofs) {
    if (0 != getField(m_fName, "First name:", false, ifs, ofs)
        || 0 != getField(m_lName, "Last name:", false, ifs, ofs)
        || 0 != getField(m_nickName, "Nickname:", false, ifs, ofs)
        || 0 != getField(m_phoneNo, "Phone number:", false, ifs, ofs)
        || 0 != getField(m_secret, "Darkest secret:", false, ifs, ofs)
    ) {
        throw std::runtime_error("Failed to initialize a contact");
    }
}
const int Contact::ToStringMode::F_NAME = 1;
const int Contact::ToStringMode::L_NAME = 2;
const int Contact::ToStringMode::NICK_NAME = 4;
const int Contact::ToStringMode::PHONE_NO = 8;
const int Contact::ToStringMode::SECRET = 16;