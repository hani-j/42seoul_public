#include "Contact.hpp"
#include <string>
#include <iomanip>

Contact::Contact(){;}

Contact::~Contact(){;}

void        Contact::set_firstname()
{
    std::string name;

    while (name.length() <= 0 && std::cin)
	{
        std::cout << "Enter your firstname : ";
        std::getline(std::cin, name);
    }
    this->_firstname = name;
}

void        Contact::set_lastname()
{
    std::string name;

    while (name.length() <= 0 && std::cin)
	{
        std::cout << "Enter your lasttname : ";
        std::getline(std::cin, name);
    }
    this->_lastname = name;
}

void        Contact::set_nickname()
{
    std::string nickname;

    while (nickname.length() <= 0 && std::cin)
	{
        std::cout << "Enter your nickname : ";
        std::getline(std::cin, nickname);
    }
    this->_nickname = nickname;
}

void        Contact::set_phone_number()
{
    std::string phone;

    while (phone.length() <= 0 && std::cin)
	{
        std::cout << "Enter your phone number : ";
        std::getline(std::cin, phone);
    }
    this->_phone_number = phone;
}

void        Contact::set_darkest_secret()
{
    std::string secret;

    while (secret.length() <= 0 && std::cin)
	{
        std::cout << "Enter your darkest secret : ";
        std::getline(std::cin, secret);
    }
    this->_darkest_secret = secret;
}

std::string Contact::get_shorten_firstname()
{
    if (this->_firstname.length() > 10)
        return (this->_firstname.substr(0, 9) + '.');
    else
        return (this->_firstname);
}

std::string Contact::get_shorten_lastname()
{
    if (this->_lastname.length() > 10)
        return (this->_lastname.substr(0, 9) + '.');
    else
        return (this->_lastname);
}

std::string Contact::get_shorten_nickname()
{
    if (this->_nickname.length() > 10)
        return (this->_nickname.substr(0, 9) + '.');
    else
        return (this->_nickname);
}

std::string Contact::get_firstname()
{
    return (this->_firstname);
}

std::string Contact::get_lastname()
{
    return (this->_lastname);
}

std::string Contact::get_nickname()
{
    return (this->_nickname);
}

std::string Contact::get_phone_number()
{
    return (this->_phone_number);
}

std::string Contact::get_darkest_secret()
{
    return (this->_darkest_secret);
}
