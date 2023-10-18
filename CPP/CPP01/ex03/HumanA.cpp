#include "HumanA.hpp"
#include <iostream>

HumanA::~HumanA(){}

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon), _name(name)
{
}

void HumanA::attack()
{
    std::cout << this->_name << " attacks with thier " << this->_weapon.getType() << std::endl;
}
