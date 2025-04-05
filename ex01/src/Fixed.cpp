#include "../include/Fixed.hpp"
#include <cmath> // For roundf
#include <iostream>

// Default constructor
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_value = other.getRawBits();
	}
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Integer constructor
Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = intValue << _fractBits;
		// Shift left to convert int to fixed-point
}

// Float constructor
Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(floatValue * (1 << _fractBits));
		// Convert float to fixed-point
}

// Getter
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
		// Removed for ex01 clarity
	return (this->_value);
}

// Setter
void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

// Convert to float
float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << _fractBits);
}

// Convert to int
int Fixed::toInt(void) const
{
	return (this->_value >> _fractBits);
		// Shift right to convert fixed-point to int
}

// Overload of the insertion (<<) operator
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
