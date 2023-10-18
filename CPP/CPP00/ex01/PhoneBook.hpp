#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact data[8];
        int     index;

    public:
        PhoneBook();
        ~PhoneBook();
        PhoneBook(const PhoneBook &p);
        PhoneBook &operator= (const PhoneBook &p);

        void    add_user();
        int     get_index(std::string str);
        void    search_user();
        void    show_manual();
        void    show_list();
};

#endif