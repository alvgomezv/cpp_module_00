# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>


class Contact
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nick_name;
        std::string _phone_number;
        std::string _secret;

    public:
        Contact(void);
        ~Contact(void);

        void    set_values(void);
};

# endif