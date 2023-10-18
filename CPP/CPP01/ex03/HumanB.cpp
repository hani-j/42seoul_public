#include "HumanB.hpp"
#include <iostream>

HumanB::~HumanB(){}

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = NULL;
}

void HumanB::attack()
{
    if (!this->_weapon)
    {
        std::cout << this->_name << " don't have weapon" << std::endl;
        return ;
    }
    std::cout << this->_name << " attacks with thier " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}