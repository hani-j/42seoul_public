#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *ret_zombie;

    ret_zombie = new Zombie(name);
    return (ret_zombie);
}
