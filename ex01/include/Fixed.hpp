#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // For roundf

class Fixed {
private:
    int                 _value;
    static const int    _fractBits = 8;

public:
    // Orthodox Canonical Form
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // New Constructors
    Fixed(const int intValue);
    Fixed(const float floatValue);

    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // New Member functions
    float toFloat(void) const;
    int toInt(void) const;
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
