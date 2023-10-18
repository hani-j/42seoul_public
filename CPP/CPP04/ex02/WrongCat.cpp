#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat's Default constructor called" << std::endl;
    this->_type = "WrongCat";
}
WrongCat::~WrongCat() 
{
	std::cout << "WrongCat's Destructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& c) : WrongAnimal()
{
	std::cout << "WrongCat's Copy constructor called" << std::endl;
    *this = c;
}
WrongCat& WrongCat::operator=(const WrongCat& c) 
{
	std::cout << "WrongCat's Copy assignment operator called" << std::endl;
    if (this != &c)
    {
        this->_type = c._type;
    }
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat : wrong meow.... wrong meow...." << std::endl;
}
