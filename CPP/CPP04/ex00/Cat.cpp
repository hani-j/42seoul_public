#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat's Default constructor called" << std::endl;
    this->_type = "Cat";
}
Cat::~Cat() 
{
	std::cout << "Cat's Destructor called" << std::endl;
}
Cat::Cat(const Cat& c) : Animal()
{
	std::cout << "Cat's Copy constructor called" << std::endl;
    this->_type = "Cat";
    *this = c;
}
Cat& Cat::operator=(const Cat& c) 
{
	std::cout << "Cat's Copy assignment operator called" << std::endl;
    if (this != &c)
    {
        this->_type = c._type;
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Cat : meow.... meow...." << std::endl;
}
