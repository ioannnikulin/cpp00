#include <iomanip>
#include <sstream>

#include "Contact.hpp"

string shorten(string field, size_t width, string terminator) {
	return (0 == width || field.length() <= width ? 
		field : 
		field.substr(0, width - 1) + terminator
	);
}

int Contact::processField(
	stringstream &ss
	, const string &field
	, const int &selector
	, int &selection
	, const Contact::ToStringMode &mode
) const {
	if (0 == (selection & selector))
		return (0);
	selection &= ~selector;
	if (mode.getWidth() != 0) {
		ss << std::setw(mode.getWidth()) << std::right << shorten(field, mode.getWidth(), mode.getTerminator());
	} else {
		ss << field;
	}
	ss << mode.getSeparator();
	return (0);
}

string Contact::toString(const ToStringMode &mode) const {
	stringstream ss;
	int selection = mode.getSelection();
	if (0 != processField(ss, m_fName, Contact::ToStringMode::F_NAME, selection, mode)
		|| 0 != processField(ss, m_lName, Contact::ToStringMode::L_NAME, selection, mode)
		|| 0 != processField(ss, m_nickName, Contact::ToStringMode::NICK_NAME, selection, mode)
		|| 0 != processField(ss, m_phoneNo, Contact::ToStringMode::PHONE_NO, selection, mode)
		|| 0 != processField(ss, m_secret, Contact::ToStringMode::SECRET, selection, mode)
	) {
		return ("");
	}
	return (ss.str());
}