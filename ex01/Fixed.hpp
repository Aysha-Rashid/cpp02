#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixedPoint;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		~Fixed();
		Fixed(const Fixed &fixedPoint);
		Fixed	&operator=(const Fixed &copy); // change this so it can accept '<<'
		float   toFloat( void ) const;
		int     toInt( void ) const;
};

#endif