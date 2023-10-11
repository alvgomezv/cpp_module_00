#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    Contact contact;
    PhoneBook phonebook;
    std::string command;

    std::cout << "** PHONEBOOK **" << std::endl;
    std::cout << "** Enter the following commands [ADD, SEARCH, EXIT] **" << std::endl;
    while (true)
    {
        std::cout << ">> ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phonebook.add_contact();
        else if (command == "SEARCH")
            phonebook.search_contact();
        else if (command == "EXIT")
        {
            std::cout << "Bye bye!" << std::endl;
            break;
        }
        else
            std::cout << "Command not available" << std::endl;
    }
    
    return (0);
}