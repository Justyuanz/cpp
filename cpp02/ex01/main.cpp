#include"Fixed.hpp"

/*
a = Fixed(1234.4321f);

what C++ actually does
Fixed temp( 1234.4321f );   // create temporary  <- Float constructor called
a = temp;                   // assign to a       <- Copy assignment operator called
temp not needed anymore  // destroy it        <- Destructor called
Compare to b, c, d — they have names so they live until return 0:
cppFixed const b( 10 );       // has name "b", lives until end of main
a = Fixed( 1234.4321f );   // no name, dies immediately after the = line
*/

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
