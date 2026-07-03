#include "Span.hpp"
#include <stdexcept>
#include <vector>
#include <iostream>

Span::Span(unsigned int capacity): _capacity(capacity)
{
	_numbers.reserve(_capacity);
}

void Span::addNumber(int n)
{
    if (_numbers.size() >= _capacity)
        throw std::runtime_error("Reached capacity.");
    _numbers.push_back(n);
	std::cout <<"Cap: " << _numbers.capacity() << std::endl;
	std::cout << "Size: " << _numbers.size() << std::endl;
}

unsigned int Span::longestSpan()
{
}
void Span::printNumbers()
{
	for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
