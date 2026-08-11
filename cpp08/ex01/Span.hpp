# pragma once

#include <cstddef>
#include <vector>
#include <iterator>
#include <stdexcept>
class Span
{
private:
    unsigned int    _capacity;
    std::vector<int> _numbers;

public:
    Span() = delete;
    Span(unsigned int capacity);
    Span(const Span& other) = default;
    ~Span() = default;

    Span& operator=(const Span& other) = default;

    void addNumber(int n);
    long long    shortestSpan();
    long long    longestSpan();

	void printNumbers();

    template <typename It>
    void addRange(It begin, It end)
    {
        long new_range = static_cast<long>(std::distance(begin, end));
        if (new_range < 0)
            throw std::runtime_error("Invalid range");
        if (_numbers.size() + new_range > _capacity)
            throw std::runtime_error("Reached capacity.");
        _numbers.insert(_numbers.end(), begin, end);
    }
};
