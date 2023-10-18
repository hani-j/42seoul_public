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


bool Fixed::operator> (const Fixed &f) const
{
	return (this->getRawBits() > f.getRawBits());
}
bool Fixed::operator< (const Fixed &f) const
{
	return (this->getRawBits() < f.getRawBits());
} 
bool Fixed::operator>= (const Fixed &f) const
{
	return (this->getRawBits() >= f.getRawBits());
}
bool Fixed::operator<= (const Fixed &f) const
{
	return (this->getRawBits() <= f.getRawBits());
}
bool Fixed::operator== (const Fixed &f) const
{
	return (this->getRawBits() == f.getRawBits());
}
bool Fixed::operator!= (const Fixed &f) const
{
	return (this->getRawBits() != f.getRawBits());
}


Fixed Fixed::operator+ (const Fixed &f) const
{
	Fixed return_fixed = Fixed(this->toFloat() + f.toFloat());
	return (return_fixed);
}
Fixed Fixed::operator- (const Fixed &f) const
{
	Fixed return_fixed = Fixed(this->toFloat() - f.toFloat());
	return (return_fixed);
}
Fixed Fixed::operator* (const Fixed &f) const
{
	Fixed return_fixed = Fixed(this->toFloat() * f.toFloat());
	return (return_fixed);
}
Fixed Fixed::operator/ (const Fixed &f) const
{
	Fixed return_fixed = Fixed(this->toFloat() / f.toFloat());
	return (return_fixed);
}


Fixed&	Fixed::operator++(void)
{
	this->_rawbits += 1;
	return (*this);
}
const Fixed	Fixed::operator++(int)
{
	const Fixed return_fixed(*this);
	this->_rawbits += 1;
	return (return_fixed);
}
Fixed&	Fixed::operator--(void)
{
	this->_rawbits -= 1;
	return (*this);
}
const Fixed	Fixed::operator--(int)
{
	const Fixed return_fixed(*this);
	this->_rawbits -= 1;
	return (return_fixed);
}


Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
