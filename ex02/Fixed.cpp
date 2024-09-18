#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
	// this->fixedPoint = 0;
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
// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
    return this->fixedPoint > other.fixedPoint;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->fixedPoint < other.fixedPoint;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->fixedPoint >= other.fixedPoint;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->fixedPoint <= other.fixedPoint;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->fixedPoint == other.fixedPoint;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->fixedPoint != other.fixedPoint;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other.fixedPoint == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Fixed(this->toFloat() / other.toFloat());
}

// Pre-increment
Fixed &Fixed::operator++() {
    this->fixedPoint++;
    return *this;
}

// Post-increment
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->fixedPoint++;
    return temp;
}

// Pre-decrement
Fixed &Fixed::operator--() {
    this->fixedPoint--;
    return *this;
}

// Post-decrement
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->fixedPoint--;
    return temp;
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}
