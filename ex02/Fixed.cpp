#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0){}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &FixedPoint) {*this  = FixedPoint;}

Fixed::Fixed(const int int_value) : fixedPoint(int_value << fractionalBits) {}

Fixed::Fixed(const float float_value) : fixedPoint(roundf(float_value * (1 << fractionalBits))) {}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->fixedPoint) / (1 << fractionalBits);
}

int Fixed::getRawBits(void) const {return (this->fixedPoint);}

void Fixed::setRawBits(int const raw) {this->fixedPoint = raw;}

Fixed& Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		this->fixedPoint = copy.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {return this->fixedPoint > other.fixedPoint;}

bool Fixed::operator<(const Fixed &other) const {return this->fixedPoint < other.fixedPoint;}

bool Fixed::operator>=(const Fixed &other) const {return this->fixedPoint >= other.fixedPoint;}

bool Fixed::operator<=(const Fixed &other) const {return this->fixedPoint <= other.fixedPoint;}

bool Fixed::operator==(const Fixed &other) const {return this->fixedPoint == other.fixedPoint;}

bool Fixed::operator!=(const Fixed &other) const {return this->fixedPoint != other.fixedPoint;}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {return Fixed(this->toFloat() + other.toFloat());}

Fixed Fixed::operator-(const Fixed &other) const {return Fixed(this->toFloat() - other.toFloat());}

Fixed Fixed::operator*(const Fixed &other) const {return Fixed(this->toFloat() * other.toFloat());}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other.fixedPoint == 0)
		throw std::runtime_error("Division by zero");
	return Fixed(this->toFloat() / other.toFloat());
}

// Pre
Fixed &Fixed::operator++() {
	this->fixedPoint++;
	return *this;
}

Fixed &Fixed::operator--() {
	this->fixedPoint--;
	return *this;
}

// Post
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->fixedPoint++;
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->fixedPoint--;
	return temp;
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {return (a < b) ? a : b;}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {return (a < b) ? a : b;}

Fixed &Fixed::max(Fixed &a, Fixed &b) {return (a > b) ? a : b;}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {return (a > b) ? a : b;}
