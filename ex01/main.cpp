#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    Contact contact;
    PhoneBook phonebook;
    std::string command;

	phonebook.print_header();
    while (true)
    {
        std::cout << ">> ";
        std::getline(std::cin, command);
        if (command == "ADD")
		{
            phonebook.add_contact();
			phonebook.print_header();
		}
        else if (command == "SEARCH")
		{
			phonebook.search_contact();
			phonebook.print_header();
		}
        else if (command == "EXIT")
        {
            std::cout << "Bye bye!" << std::endl;
            break;
        }
		else if (command.empty())
			continue ;
        else
            std::cout << "Command not available" << std::endl;
    }
    
    return (0);
}