#include "Contact.hpp"
#include <iostream>

//constructor
Contact::Contact()
{
}

//destructor
Contact::~Contact()
{
}

//pass by reference. avoids copying
void Contact::setFirstName(const std::string &first_name)
{
	_first_name = first_name;
}

void Contact::setLastName(const std::string &last_name)
{
	_last_name = last_name;
}

void Contact::setNickName(const std::string &nick_name)
{
	_nick_name = nick_name;
}

void Contact::setPhoneNumber(const std::string &phone_number)
{
	_phone_number = phone_number;
}

void Contact::setDarkSecret(const std::string &dark_secret)
{
	_dark_secret = dark_secret;
}

std::string Contact::getFirstName(void) const
{
	return _first_name;
}

std::string Contact::getLastName(void) const
{
	return _last_name;
}

std::string Contact::getNickName(void) const
{
	return _nick_name;
}

std::string Contact::getPhoneNumber(void) const
{
	return _phone_number;
}

std::string Contact::getDarkSecret(void) const
{
	return _dark_secret;
}