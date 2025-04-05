#include <iostream>
#include "Fixed.hpp"

// Constructeur par défaut
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructeur de recopie
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Surcharge de l'opérateur d'affectation
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other.getRawBits();
    }
    return *this;
}

// Destructeur
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Getter pour la valeur brute
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

// Setter pour la valeur brute
void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}