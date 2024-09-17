#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _rawBits;
    static const int _fractionalBits = 8; // Assume 8 bits for the fractional part

public:
    // Constructor that accepts a floating-point number and converts it to fixed-point
    Fixed(float number)
    {
        _rawBits = roundf(number * (1 << _fractionalBits)); // Scale by 256 (2^8)
    }

    // Convert fixed-point back to floating-point
    float toFloat() const
    {
        return (float)_rawBits / (1 << _fractionalBits); // Divide by 256 (2^8)
    }

    // Print raw bits for debugging
    void printRawBits() const
    {
        std::cout << "Raw bits: " << _rawBits << std::endl;
    }
};

int main()
{
    Fixed number(5.75); // Create a Fixed object with the value 5.75

    number.printRawBits(); // Print the raw fixed-point representation
    // std::cout << "Converted back to float: " << number.toFloat() << std::endl; // Should print 5.75

    return 0;
}
