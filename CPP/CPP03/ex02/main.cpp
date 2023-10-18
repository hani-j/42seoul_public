#include "FragTrap.hpp"

int main (void)
{
    FragTrap fragTrap("Young-hee");
    
    fragTrap.printInfo();
    fragTrap.attack("Cheol-soo");
    fragTrap.printInfo();
    fragTrap.takeDamage(50);
    fragTrap.printInfo();
    fragTrap.beRepaired(30);
    fragTrap.printInfo();
    fragTrap.takeDamage(100);
    fragTrap.printInfo();
    fragTrap.attack("Cheol-soo");
    fragTrap.printInfo();
    fragTrap.beRepaired(3);
}