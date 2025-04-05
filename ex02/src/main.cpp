#include "../include/Fixed.hpp"
#include <iostream>

int	main(void)
{
	Fixed	a;

	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	// My tests
	Fixed c(10);
	Fixed d(5);
	Fixed e(5);
	std::cout << "--- My Tests ---" << std::endl;
	std::cout << "c = " << c << ", d = " << d << ", e = " << e << std::endl;
	// Comparisons
	std::cout << "c > d: " << (c > d) << std::endl;   // 1 (true)
	std::cout << "c < d: " << (c < d) << std::endl;   // 0 (false)
	std::cout << "d == e: " << (d == e) << std::endl; // 1 (true)
	std::cout << "d != e: " << (d != e) << std::endl; // 0 (false)
	std::cout << "c >= d: " << (c >= d) << std::endl; // 1 (true)
	std::cout << "d <= e: " << (d <= e) << std::endl; // 1 (true)
	// Arithmetic
	std::cout << "c + d: " << (c + d) << std::endl; // 15
	std::cout << "c - d: " << (c - d) << std::endl; // 5
	std::cout << "c * d: " << (c * d) << std::endl; // 50
	std::cout << "c / d: " << (c / d) << std::endl; // 2
	// Increment/Decrement
	std::cout << "d before --: " << d << std::endl; // 5
	std::cout << "--d: " << --d << std::endl;       // 4
	std::cout << "d after --: " << d << std::endl;  // 4
	std::cout << "d--: " << d-- << std::endl;      
		// 4 (returns original value)
	std::cout << "d after d--: " << d << std::endl; // 3
	// Min/Max
	Fixed f(2.5f);
	Fixed g(3.5f);
	std::cout << "min(f, g): " << Fixed::min(f, g) << std::endl; // 2.5
	std::cout << "max(f, g): " << Fixed::max(f, g) << std::endl; // 3.5
	const Fixed h(1.1f);
	const Fixed i(1.2f);
	std::cout << "min(const h, const i): " << Fixed::min(h, i) << std::endl;
		// 1.1
	std::cout << "max(const h, const i): " << Fixed::max(h, i) << std::endl;
		// 1.2
	return (0);
}
