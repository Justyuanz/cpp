#include"Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	//00001010 << 8 = 1010 00000000 (10 becomes 2560, multiplied by 256)
	_value = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	//scale up by 2^8 to store the fractional part as an integer
	_value = (int)(roundf(n * (1 << _fractionalBits)));
}

float Fixed::toFloat(void) const
{
	//scale back down by 2^8 to recover the original decimal value
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	//drop fractional part by shifting right
	return (_value >> _fractionalBits);
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
  	out << value.toFloat();
  	return (out);
}


