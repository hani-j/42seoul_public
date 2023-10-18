#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << this->_name << "'s Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << "'s Destructor called" << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap& c)
{
    *this = c;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap& c)
{
    if (this != &c)
    {
        this->_name = c._name;
        this->_attackDamage = c._attackDamage;
        this->_energyPoints = c._energyPoints;
        this->_hitPoints = c._hitPoints;
    }
	std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

ClapTrap::ClapTrap(std::string name)
{
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
	std::cout << this->_name << "'s Name constructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        this->_energyPoints -= 1;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints > 0)
    {
        if (this->_hitPoints < amount)
            this->_hitPoints = 0;
        else
            this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage." << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints > 0 && this->_energyPoints > 0)
    {
        this->_hitPoints += amount;
        this->_energyPoints -= 1;
        std::cout << "ClapTrap " << this->_name << " is repaired " << amount << " points." << std::endl;
    }
}

void ClapTrap::printInfo()
{
    std::cout << "===================================" << std::endl;
    std::cout << "name : " << this->_name << std::endl;
    std::cout << "hp : " << this->_hitPoints << std::endl;
    std::cout << "ep : " << this->_energyPoints << std::endl;
    std::cout << "===================================" << std::endl;
}

