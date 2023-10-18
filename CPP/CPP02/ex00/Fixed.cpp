#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawbits = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	// if (this != &f)
	// 	this->_rawbits = f.getRawBits();
	*this = f;
}

Fixed& Fixed::operator= (const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		this->_rawbits = f.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawbits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawbits = raw;
}
