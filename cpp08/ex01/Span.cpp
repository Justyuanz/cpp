#include "Span.hpp"
#include <stdexcept>
#include <vector>

Span::Span(unsigned int capacity): _capacity(capacity)
{
}

void Span::addNumber(int n)
{
    std::vector<int> vec(_capacity);
    if (vec.size() >= _capacity)
        throw std::runtime_error("Reached capacity.");
    vec.push_back(n);
}