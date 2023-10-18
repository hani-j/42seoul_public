#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog's Default constructor called" << std::endl;
    this->_type = "Dog";
}
Dog::~Dog() 
{
	std::cout << "Dog's Destructor called" << std::endl;
}
Dog::Dog(const Dog& d) : Animal()
{
	std::cout << "Dog's Copy constructor called" << std::endl;
    this->_type = "Dog";
    *this = d;
}
Dog& Dog::operator=(const Dog& d)
{
	std::cout << "Dog's Copy assignment operator called" << std::endl;
    if (this != &d)
    {
        this->_type = d._type;
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Dog : Bow-wow!! Bow-wow!!" << std::endl;
}
