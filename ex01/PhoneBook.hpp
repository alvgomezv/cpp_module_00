#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include<iostream>
#include"Contact.hpp"

class PhoneBook
{
    private:
        Contact 		_contacts[8];
        static int     _count;

    public:
        PhoneBook(void);
        ~PhoneBook(void);

    	void    add_contact(void);
    	void    search_contact(void);
		void	print_header(void) const;
};

#endif