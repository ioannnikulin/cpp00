#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
	: m_curContact(0)
	, m_addedContacts(0)
{
}

PhoneBook::PhoneBook(const PhoneBook &other)
	: m_curContact(other.m_curContact)
	, m_addedContacts(other.m_addedContacts)
{
	for (int i = 0; i < other.m_addedContacts; i ++) {
		m_contacts[i] = other.m_contacts[i];
	}
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other) {
	if (this != &other) {
		m_curContact = other.m_curContact;
		m_addedContacts = other.m_addedContacts;
		for (int i = 0; i < other.m_addedContacts; i ++) {
			m_contacts[i] = other.m_contacts[i];
		}
	}
	return (*this);
}

PhoneBook::~PhoneBook() {
}