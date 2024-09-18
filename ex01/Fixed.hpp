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
		Fixed(const int int_value);
		Fixed(const float float_value);
		Fixed(const Fixed &fixedPoint);
		Fixed	&operator=(const Fixed &copy);
		~Fixed();
	
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float   toFloat( void ) const;
		int     toInt( void ) const;
};
		std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif