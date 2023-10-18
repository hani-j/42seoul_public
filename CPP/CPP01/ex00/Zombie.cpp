#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
    ;
}

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
