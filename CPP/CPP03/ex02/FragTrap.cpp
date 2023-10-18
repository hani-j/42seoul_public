#include "FragTrap.hpp"

FragTrap::FragTrap() 
{
    std::cout << "FragTrap " << this->_name << "'s Default constructor called" << std::endl;
}
FragTrap::~FragTrap() 
{
	std::cout << "FragTrap " << this->_name << "'s Destructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap& f) 
{
    *this = f;
	std::cout << "FragTrap " << this->_name << "'s Copy constructor called" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& f) 
{
    if (this != &f)
    {
        this->_name = f._name;
        this->_attackDamage = f._attackDamage;
        this->_energyPoints = f._energyPoints;
        this->_hitPoints = f._hitPoints;
    }
	std::cout << "FragTrap " << this->_name << "'s Copy assignment operator called" << std::endl;
    return (*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap " << this->_name << "'s Name constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

void FragTrap::highFivesGuys(void)
{
    if (this->_hitPoints)
        std::cout << "Let's high five!!!" << std::endl;
}
