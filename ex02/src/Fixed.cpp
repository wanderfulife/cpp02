#include "../include/Fixed.hpp"
#include <cmath> // For roundf
#include <iostream>

// --- Canonical Form & Constructors/Destructor (from ex01) ---
Fixed::Fixed() : _value(0)
{
 /* std::cout << "Default constructor called" << std::endl; */
}
Fixed::Fixed(const Fixed &other)
{
 /* std::cout << "Copy constructor called" << std::endl; */
	*this = other;
}
Fixed &Fixed::operator=(const Fixed &other)
{
 /* std::cout << "Copy assignment operator called" << std::endl; */
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}
Fixed::~Fixed()
{
 /* std::cout << "Destructor called" << std::endl; */
}
Fixed::Fixed(const int intValue) : _value(intValue << _fractBits)
{
 /* std::cout << "Int constructor called" << std::endl; */
}
Fixed::Fixed(const float floatValue) : _value(roundf(floatValue
		* (1 << _fractBits)))
{
 /* std::cout << "Float constructor called" << std::endl; */
}

// --- Getters/Setters & Conversion (from ex01) ---
int Fixed::getRawBits(void) const
{
	return (this->_value);
}
void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << _fractBits);
}
int Fixed::toInt(void) const
{
	return (this->_value >> _fractBits);
}

// --- Comparison Operators (ex02) ---
bool Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other.getRawBits());
}
bool Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other.getRawBits());
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other.getRawBits());
}
bool Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other.getRawBits());
}

// --- Arithmetic Operators (ex02) ---
Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}
Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}
Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}
Fixed Fixed::operator/(const Fixed &other) const
{
	// Consider adding check for division by zero if required
	return (Fixed(this->toFloat() / other.toFloat()));
}

// --- Increment/Decrement Operators (ex02) ---
// Pre-increment
Fixed &Fixed::operator++()
{
	this->_value++;
	return (*this);
}
// Post-increment
Fixed Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	++(*this); // Use pre-increment
	return (temp);
}
// Pre-decrement
Fixed &Fixed::operator--()
{
	this->_value--;
	return (*this);
}
// Post-decrement
Fixed Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	--(*this); // Use pre-decrement
	return temp;
}

// --- Static Member Functions (ex02) ---
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

// --- Insertion Operator Overload (from ex01) ---
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
