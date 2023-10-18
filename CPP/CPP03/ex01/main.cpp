#include "ScavTrap.hpp"

int main (void)
{
    ScavTrap scavTrap("Young-hee");
    
    scavTrap.printInfo();
    scavTrap.attack("Cheol-soo");
    scavTrap.printInfo();
    scavTrap.takeDamage(50);
    scavTrap.printInfo();
    scavTrap.beRepaired(30);
    scavTrap.printInfo();
    scavTrap.guardGate();
    scavTrap.takeDamage(100);
    scavTrap.attack("Cheol-soo");
    scavTrap.printInfo();
    scavTrap.beRepaired(3);
}