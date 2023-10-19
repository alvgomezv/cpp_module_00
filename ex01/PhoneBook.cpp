#include"PhoneBook.hpp"
#include"Contact.hpp"

int PhoneBook::_count = 0;

PhoneBook::PhoneBook(void)
{
	this->_count = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void    PhoneBook::add_contact(void)
{
	this->_contacts[_count % 8].set_values();
	_count++;
}

void    PhoneBook::search_contact(void)
{
	std::string str;
	int			max_i;
	
	if (this->_count == 0)
	{
		std::cout << std::endl;
		std::cout << "The PhoneBook is empty." << std::endl;
		std::cout << std::endl;
		return ;
	}
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	if (_count < 8)
		max_i = this->_count;
	else
		max_i = 8;
	for (int i = 0; i < max_i; i++)
	{
		std::cout << "|" << std::right << std::setw(10) << i + 1 << "|";
		if (this->_contacts[i].get_value("first name").length() > 10)
			str = this->_contacts[i].get_value("first name").substr(0, 9) + ".";
		else
			str = this->_contacts[i].get_value("first name");
		std::cout << std::right << std::setw(10) << str << "|";
		if (this->_contacts[i].get_value("last name").length() > 10)
			str = this->_contacts[i].get_value("last name").substr(0, 9) + ".";
		else
			str = this->_contacts[i].get_value("last name");
		std::cout << std::right << std::setw(10) << str << "|";
		if (this->_contacts[i].get_value("nickname").length() > 10)
			str = this->_contacts[i].get_value("nickname").substr(0, 9) + ".";
		else
			str = this->_contacts[i].get_value("nickname");
		std::cout << std::right << std::setw(10) << str << "|" << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, str);
	while (str.empty() || str.length() > 1 || str[0] < '1' || str[0] > '8' || std::stoi(str) > this->_count)
	{
		if (str.empty())
			std::cout << "Index cannot be empty" << std::endl;
		else if (str.length() > 1 || str[0] < '1' || str[0] > '8')
			std::cout << "Index must be a number between 1 and 8" << std::endl;
		else if (std::stoi(str) > this->_count)
			std::cout << "Index out of range" << std::endl;
		std::cout << "Enter the index of the contact you want to see: ";
		std::getline(std::cin, str);
	}
	std::cout << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|First Name: " << this->_contacts[std::stoi(str) - 1].get_value("first name") << std::endl;
	std::cout << "|Last Name: " << this->_contacts[std::stoi(str) - 1].get_value("last name") << std::endl;
	std::cout << "|Nickname: " << this->_contacts[std::stoi(str) - 1].get_value("nickname") << std::endl;
	std::cout << "|Phone Number: " << this->_contacts[std::stoi(str) - 1].get_value("phone number") << std::endl;
	std::cout << "|Darkest Secret: " << this->_contacts[std::stoi(str) - 1].get_value("darkest secret") << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::print_header(void) const
{
	std::cout << "** PHONEBOOK **" << std::endl;
	std::cout << "** Enter the following commands [ADD, SEARCH, EXIT] **" << std::endl;
}