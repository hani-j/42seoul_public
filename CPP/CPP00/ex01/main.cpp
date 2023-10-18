#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main(void)
{
    PhoneBook   phonebook;
    std::string input;

    while (input != "EXIT" && std::cin)
    {
        phonebook.show_manual();
        std::getline(std::cin, input);
        if (input == "ADD")
            phonebook.add_user();
        else if (input == "SEARCH")
            phonebook.search_user();
    }
    std::cout << "Exit Program"; std::cout << std::endl;
    return (0);
}