#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
        ClapTrap();
    public:
        ~ClapTrap();
        ClapTrap (const ClapTrap& c);
        ClapTrap& operator= (const ClapTrap& c);

        ClapTrap(std::string name);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        void printInfo();
};

#endif