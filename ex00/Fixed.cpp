#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &FixedPoint) : fixedPoint(FixedPoint.fixedPoint)
{
	// std::cout << "Copy constructor called" << std::endl;
	// copy constructor is responsible for deciding whether
	// to perform a shallow copy or a deep copy.
	// a shallow copy simple copies the values of data members,
	// while a deep copy involves creating a new copies of dynamically 
	// allocated resources.
	std::cout << "Copy constructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->fixedPoint = copy.getRawBits();
	return (*this);
}
