#include "Harl.hpp"

Harl::Harl()
{
    this->_level[0] = "DEBUG";
    this->_level[1] = "INFO";
    this->_level[2] = "WARNING";
    this->_level[3] = "ERROR";
    this->find_function[0] = &Harl::_debug;
    this->find_function[1] = &Harl::_info;
    this->find_function[2] = &Harl::_warning;
    this->find_function[3] = &Harl::_error;
}

Harl::~Harl()
{
}

void Harl::_debug(void)
{
    std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::_info(void)
{
    std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning(void)
{
    std::cout << "WARNING : I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
    std::cout << "ERROR : This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4; i++)
    {
        if (level == this->_level[i])
        {
            (this->*find_function[i])();
            return ;
        }
    }
    std::cerr << "No Exist Level" << std::endl;
}
