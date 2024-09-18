#include "Fixed.hpp"

int main( void ) 
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;

	// std::cout << "address a : " << &a << std::endl;
	// std::cout << "address b : " << &b << std::endl;
	// std::cout << "address c : " << &c << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}