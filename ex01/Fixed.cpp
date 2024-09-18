#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
	// this->fixedPoint = 0;
}

Fixed::Fixed(const int int_value) : fixedPoint(int_value << fractionalBits)
{
	//fixed point is initialized after shifting it by the fractional bits
	// convert a int value to a fixed point representation
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_value) : fixedPoint(roundf(float_value * (1 << fractionalBits)))
{
	// is calculated by converting the float to fixed-point representation using scaling

	// a floating-point value (float_value) and scales it by multiplying it by 2 fractionalBits
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &FixedPoint)
{
	*this  = FixedPoint;
	std::cout << "Copy constructor called" << std::endl;
}

float   Fixed::toFloat( void ) const
{
    return ((float)this->getRawBits() / (1 << this->fractionalBits));
}

int   Fixed::toInt( void ) const
{
    return (this->fixedPoint >> this->fractionalBits);
}

int Fixed::getRawBits(void) const
{
	return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->fixedPoint = copy.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
