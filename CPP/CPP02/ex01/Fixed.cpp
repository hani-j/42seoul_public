#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_rawbits = 0;
}

Fixed::Fixed(const int integer) : _rawbits(integer << this->_literal)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_num) : _rawbits(roundf(float_num * (1 << this->_literal)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
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
	return (this->_rawbits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawbits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_rawbits) / (1 << this->_literal));
}

int Fixed::toInt(void) const
{
	return (this->_rawbits >> this->_literal);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}


