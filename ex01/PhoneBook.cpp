#include"PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    //std::cout << "PhoneBook constructor called" << std::endl;
    this->_count = 0;
    return ;
}

PhoneBook::~PhoneBook(void)
{
    //std::cout << "PhoneBook destructor called" << std::endl;
    return ;
}

void    PhoneBook::add_contact(void)
{
    _contacts[_count % 8].set_values();
    _count++;
}

void    PhoneBook::search_contact(void)
{
    if (_count == 0)
    {
        std::cout << "The PhoneBook is empty." << std::endl;
		return ;
    }
    std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
    
}