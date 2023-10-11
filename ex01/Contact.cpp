#include "Contact.hpp"

Contact::Contact(void)
{
    //std::cout << "Contact constructor called" << std::endl;
    return ;
}

Contact::~Contact(void)
{
    //std::cout << "Contact destructor called" << std::endl;
    return ;
}

void    Contact::set_values(void)
{
    std::cout << "** First name: ";
	std::getline(std::cin, _first_name);
    while (_first_name.empty())
    {
        std::cout << "First name cannot be empty";
        std::cout << "** First name: ";
	    std::getline(std::cin, _first_name);
    }
	std::cout << "** Last name: ";
	std::getline(std::cin, _last_name);
    while (_last_name.empty())
    {
        std::cout << "Last name cannot be empty";
        std::cout << "** Last name: ";
	    std::getline(std::cin, _last_name);
    }
	std::cout << "** Nickname: ";
	std::getline(std::cin, _nick_name);
    while (_nick_name.empty())
    {
        std::cout << "Nickname cannot be empty";
        std::cout << "** Nickname: ";
	    std::getline(std::cin, _nick_name);
    }
	std::cout << "** Phone Number: ";
	std::getline(std::cin, _phone_number);
    while (_phone_number.empty())
    {
        std::cout << "Phone number cannot be empty";
        std::cout << "** Phone number: ";
	    std::getline(std::cin, _phone_number);
    }
	std::cout << "** Darkest Secret: ";
	std::getline(std::cin, _secret);
    while (_secret.empty())
    {
        std::cout << "Darkest Secret cannot be empty";
        std::cout << "** Darkest Secret: ";
	    std::getline(std::cin, _secret);
    }
	std::cout << "** Contact created succesfully!" << std::endl;
}