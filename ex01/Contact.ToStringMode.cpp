#include "Contact.hpp"

Contact::ToStringMode &Contact::ToStringMode::operator=(const Contact::ToStringMode &other) {
	if (this != &other) {
		m_selection = other.m_selection;
		m_width = other.m_width;
		m_separator = other.m_separator;
		m_terminator = other.m_terminator;
	}
	return (*this);
}

int Contact::ToStringMode::getSelection() const {
	return (m_selection);
}

int Contact::ToStringMode::getWidth() const {
	return (m_width);
}

string Contact::ToStringMode::getTerminator() const {
	return (m_terminator);
}

string Contact::ToStringMode::getSeparator() const {
	return (m_separator);
}

Contact::ToStringMode::ToStringMode(int selection, int width, string terminator, string separator)
	: m_selection(selection)
	, m_width(width)
	, m_terminator(terminator)
	, m_separator(separator)
{}

Contact::ToStringMode::~ToStringMode() {
}