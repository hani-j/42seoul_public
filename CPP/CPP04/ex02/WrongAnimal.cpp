#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
    std::cout << "WrongAnimal's Default constructor called" << std::endl;
    this->_type = "default";
}
WrongAnimal::~WrongAnimal() 
{
	std::cout << "WrongAnimal's Destructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& a) 
{
	std::cout << "WrongAnimal's Copy constructor called" << std::endl;
    *this = a;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a) 
{
	std::cout << "WrongAnimal's Copy assignment operator called" << std::endl;
    if (this != &a)
    {
        this->_type = a._type;
    }
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return (this->_type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal : I don't make a sound" << std::endl;
}
