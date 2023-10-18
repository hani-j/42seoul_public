#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap claptrap("Cheol-soo");

    claptrap.printInfo();
    claptrap.attack("Young-hee");
    claptrap.takeDamage(5);
    claptrap.printInfo();
    claptrap.beRepaired(3);
    claptrap.printInfo();
    claptrap.takeDamage(10);
    claptrap.printInfo();
    claptrap.attack("Young-hee");
    claptrap.beRepaired(3);
}