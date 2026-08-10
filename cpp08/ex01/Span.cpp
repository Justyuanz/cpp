#include "Span.hpp"
#include <climits>
#include <cstddef>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>

Span::Span(unsigned int capacity): _capacity(capacity)
{
	_numbers.reserve(_capacity); //vector pre-allocate memory for _capacity elements, does not change size()
}

void Span::addNumber(int n)
{
    if (_numbers.size() >= _capacity)
        throw std::runtime_error("Reached capacity.");
    _numbers.push_back(n);
	// std::cout <<"Cap: " << _numbers.capacity() << std::endl;
	// std::cout << "Size: " << _numbers.size() << std::endl;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("fewer than 2 stored numbers");

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}

int Span::shortestSpan()
{

    if (_numbers.size() < 2)
        throw std::runtime_error("fewer than 2 stored numbers");

    std::sort(_numbers.begin(), _numbers.end());
    int span;
    int min_span = _numbers[1] - _numbers[0];
    for (std::size_t i = 1; i < _numbers.size(); i++)
    {
        span = _numbers[i] - _numbers[i - 1];
        if (span < min_span)
            min_span = span;
    }
    return min_span;
}

void Span::printNumbers()
{
	for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
