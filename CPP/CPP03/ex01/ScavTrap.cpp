#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << "'s Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << this->_name << "'s Name constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << "'s Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s)
{
    *this = s;
	std::cout << "ScavTrap " << this->_name << "'s Copy constructor called" << std::endl;
}
ScavTrap& ScavTrap::operator= (const ScavTrap& s)
{
    if (this != &s)
    {
        this->_name = s._name;
        this->_attackDamage = s._attackDamage;
        this->_energyPoints = s._energyPoints;
        this->_hitPoints = s._hitPoints;
    }
	std::cout << "ScavTrap " << this->_name << "'s Copy assignment operator called" << std::endl;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        this->_energyPoints -= 1;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    if (this->_hitPoints > 0)
        std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}