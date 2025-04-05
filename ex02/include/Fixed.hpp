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

    // Constructors from ex01
    Fixed(const int intValue);
    Fixed(const float floatValue);

    // Member functions from ex00/ex01
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    // Comparison Operators (ex02)
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic Operators (ex02)
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment/Decrement Operators (ex02)
    Fixed& operator++();        // Pre-increment
    Fixed operator++(int);     // Post-increment
    Fixed& operator--();        // Pre-decrement
    Fixed operator--(int);     // Post-decrement

    // Static Member Functions (ex02)
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

};

// Overload of the insertion operator (from ex01)
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
