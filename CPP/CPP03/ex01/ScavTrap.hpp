#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        ScavTrap();
    public:
        ~ScavTrap();
        ScavTrap(const ScavTrap& s);
        ScavTrap& operator= (const ScavTrap& s);

        ScavTrap(std::string name);
        
        void attack(const std::string& target);
        void guardGate();
};

#endif