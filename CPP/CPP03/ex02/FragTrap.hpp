#ifndef  FRAGTRAP_HPP
#define  FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        FragTrap();
    public:
        FragTrap(const  FragTrap& obj);
        ~FragTrap();
        FragTrap& operator=(const  FragTrap& obj);

        FragTrap(std::string name);

        void highFivesGuys(void);
};

#endif


