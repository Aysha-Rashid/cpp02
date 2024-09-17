#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int fixedPoint;
		static const int fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixedPoint);
		Fixed	&operator=(const Fixed &copy);
		// Fixed &Fixed::operator=(const Fixed&);
		// copy constructor
		// copy assignment operator overload
		int		getRawBits(void)const;
		void	setRawBits(int const raw);

};

#endif