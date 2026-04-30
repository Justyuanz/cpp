# ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
	int	_value;
	static const int	_fractionalBits = 8; // like a global constant shared by all, within class.
	public:
	Fixed();
	~Fixed();

	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};
#endif