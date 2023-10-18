#ifndef HARL_HPP
# define HARL_HPP
#include <iostream>
# include <string>

class Harl
{
    private:
        std::string _level[4];

        void _debug(void);
        void _info(void);
        void _warning(void);
        void _error(void);
        void (Harl::*find_function[4])();

    public:
        Harl();
        ~Harl();

        void complain(std::string level);
};

#endif