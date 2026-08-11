#include "Span.hpp"
#include <exception>
#include <iostream>
#include <vector>

int main()
{
	Span sp = Span(5);
    Span small = Span(1);
    Span range = Span(5);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(42);
    }
    catch (std::exception &e)
    {
		std::cerr << e.what() << std::endl;
    }

	sp.printNumbers();
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp.longestSpan() << std::endl;

    try
    {
        small.addNumber(7);
        small.longestSpan();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::vector<int> rangeValues = {2,3,5,7,15};
        range.addRange(rangeValues.begin(), rangeValues.end());
        std::cout << "range shortest span: " << range.shortestSpan() << std::endl;
        std::cout << "range longest span: " << range.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	return 0;
}
