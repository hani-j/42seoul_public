#include "PhoneBook.hpp"
#include <string>
#include <iomanip>

PhoneBook::PhoneBook()
{
    this->index = 0;
}

PhoneBook::~PhoneBook(){;}

void    PhoneBook::add_user()
{
    if (this->index == 8)
        this->index = 0;
    data[index].set_firstname();
    data[index].set_lastname();
    data[index].set_nickname();
    data[index].set_phone_number();
    data[index].set_darkest_secret();
    this->index++;
}

int    PhoneBook::get_index(std::string str)
{
    if (str == "1")
        return (0);
    else if (str == "2")
        return (1);
    else if (str == "3")
        return (2);
    else if (str == "4")
        return (3);
    else if (str == "5")
        return (4);
    else if (str == "6")
        return (5);
    else if (str == "7")
        return (6);
    else if (str == "8")
        return (7);
    else
        return (-1);
}

void    PhoneBook::search_user()
{
    std::string input;

    show_list();
    std::cout << "Enter index or q (quit)" << std::endl;
    getline(std::cin, input);
    while (input != "q" && std::cin)
    {
        if (get_index(input) != -1 && data[get_index(input)].get_firstname().length())
        {
            std::cout << "-------------------------" << std::endl;
            std::cout << "firstname : " << data[get_index(input)].get_firstname() << std::endl; 
            std::cout << "lasttname : " << data[get_index(input)].get_lastname() << std::endl; 
            std::cout << "nickname : " << data[get_index(input)].get_nickname() << std::endl; 
            std::cout << "phonenumber : " << data[get_index(input)].get_phone_number() << std::endl;
            std::cout << "darkest secret : " << data[get_index(input)].get_darkest_secret() << std::endl;
            std::cout << "-------------------------" << std::endl;
        }
        std::cout << "Enter index or q (quit)" << std::endl;
        getline(std::cin, input);
    }
}

void    PhoneBook::show_manual()
{
    std::cout << "-------------------------" << std::endl;
    std::cout << "Enter Command" << std::endl;
    std::cout << "1. ADD" << std::endl;
    std::cout << "2. SEARCH" << std::endl;
    std::cout << "3. EXIT" << std::endl;
    std::cout << "-------------------------" << std::endl;
}

void    PhoneBook::show_list()
{
    std::cout << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << std::setw(10) << "index" << "|" << std::setw(10) << "firstname" << "|" << std::setw(10) << "lastname" << "|" << std::setw(10) << "nickname" << std::endl;
    std::cout << "===========================================" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|" << std::setw(10) << data[i].get_shorten_firstname() << "|" << std::setw(10) << data[i].get_shorten_lastname() << "|" << std::setw(10) << data[i].get_shorten_nickname() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::endl;
}
