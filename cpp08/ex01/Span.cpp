#include "Span.hpp"
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
}

long long Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("fewer than 2 stored numbers");

    long long min = *std::min_element(_numbers.begin(), _numbers.end());
    long long max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}

long long Span::shortestSpan()
{

    if (_numbers.size() < 2)
        throw std::runtime_error("fewer than 2 stored numbers");

    std::vector<int> copy = _numbers;
    std::sort(copy.begin(), copy.end());
    long long span;
    long long min_span = static_cast<long long>(copy[1]) - static_cast<long long>(copy[0]);
    for (std::size_t i = 1; i < copy.size(); i++)
    {
        span = static_cast<long long>(copy[i]) - static_cast<long long>(copy[i - 1]);
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
