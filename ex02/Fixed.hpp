#ifndef FIXED_HPP
#define FIXED_HPP
#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int fixedPoint;
		static const int fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixedPoint);
		Fixed	&operator=(const Fixed &copy); // overload member function

};

#endif