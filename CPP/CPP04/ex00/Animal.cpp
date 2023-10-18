#include "Animal.hpp"

Animal::Animal() 
{
    std::cout << "Animal's Default constructor called" << std::endl;
    this->_type = "default";
}
Animal::~Animal() 
{
	std::cout << "Animal's Destructor called" << std::endl;
}
Animal::Animal(const Animal& a) 
{
	std::cout << "Animal's Copy constructor called" << std::endl;
    *this = a;
}
Animal& Animal::operator=(const Animal& a) 
{
	std::cout << "Animal's Copy assignment operator called" << std::endl;
    if (this != &a)
    {
        this->_type = a._type;
    }
    return (*this);
}

std::string Animal::getType() const
{
    return (this->_type);
}

void Animal::makeSound() const
{
    std::cout << "Animal : I don't make a sound" << std::endl;
}
