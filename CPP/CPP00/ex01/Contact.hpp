#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
    private:
        std::string _firstname;
        std::string _lastname;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;

    public:
        Contact();
        ~Contact();
        Contact(const Contact &c);
        Contact &operator= (const Contact &c);

        void        set_firstname();
        std::string get_firstname();

        void        set_lastname();
        std::string get_lastname();
        
        void        set_nickname();
        std::string get_nickname();
        
        void        set_phone_number();
        std::string get_phone_number();
        
        void        set_darkest_secret();
        std::string get_darkest_secret();

        std::string get_shorten_firstname();
        std::string get_shorten_lastname();
        std::string get_shorten_nickname();
};

#endif