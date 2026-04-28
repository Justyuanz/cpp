#include"Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::Fixed(const int n)
{
	_value = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
	_value = (int)(roundf(n * (1 << _fractionalBits)));
}

float Fixed::toFloat(void) const
{
	return (float)(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this == &other)
		return (*this);
	_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
	return(_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

bool Fixed::operator>(const Fixed &other) const
{
	return(this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return(this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return(this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return(this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return(this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return(this->_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return(Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return(Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return(Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.getRawBits() == 0)
		return (Fixed(0));
	return(Fixed(this->toFloat() / other.toFloat()));
}

// ++/-- move by one raw fixed-point step (1 / 256 when fractionalBits = 8)
// prefix: returns reference to self (already changed)
Fixed &Fixed::operator++(void)
{
	_value++;
	return (*this);
}

//postfix - saves old, modifies self, returns copy of old
Fixed Fixed::operator++(int)
{
	Fixed old = *this;
    _value++; 
    return (old);
}
Fixed &Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
    _value--;
    return (old);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
  	out << value.toFloat();
  	return (out);
}

