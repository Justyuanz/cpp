# pragma once

#include <cstddef>
#include <vector>
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
    //void addMultipleNumbers();
    //unsigned int    shortestSpan();
    unsigned int    longestSpan();

	void printNumbers();
};
