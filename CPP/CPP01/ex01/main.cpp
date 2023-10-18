#include "Zombie.hpp"
#include <iostream>

int main()
{
    Zombie*     zombies;
    int         num = 5;
    std::string name = "zzombbie";

    zombies = zombieHorde(num, name);
    for (int i = 0; i < num; i++)
        zombies[i].announce();
    delete[] zombies;
}