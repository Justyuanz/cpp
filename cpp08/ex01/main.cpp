#include "Span.hpp"
#include <exception>
#include <iostream>
#include <vector>

int main()
{
	Span sp = Span(5);
    Span small = Span(1);
    Span range = Span(5);
    Span duplicate = Span(4);
    Span negative = Span(5);
    Span rangeOverflow = Span(3);

    std::cout << "--------------test basic span-------------" << std::endl;
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

    std::cout << "--------------test small span-------------" << std::endl;
    try
    {
        small.addNumber(7);
        small.longestSpan();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--------------test add range-------------" << std::endl;
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

    std::cout << "--------------test duplicate numbers-------------" << std::endl;
    try
    {
        duplicate.addNumber(10);
        duplicate.addNumber(10);
        duplicate.addNumber(20);
        duplicate.addNumber(30);
        std::cout << "duplicate shortest span: " << duplicate.shortestSpan() << std::endl;
        std::cout << "duplicate longest span: " << duplicate.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--------------test negative numbers-------------" << std::endl;
    try
    {
        negative.addNumber(-10);
        negative.addNumber(-3);
        negative.addNumber(0);
        negative.addNumber(8);
        negative.addNumber(15);
        std::cout << "negative shortest span: " << negative.shortestSpan() << std::endl;
        std::cout << "negative longest span: " << negative.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "--------------test range overflow-------------" << std::endl;
    try
    {
        std::vector<int> overflowValues = {1,2,3,4};
        rangeOverflow.addRange(overflowValues.begin(), overflowValues.end());
    }
    catch (std::exception &e)
    {
        std::cerr << "range overflow: " << e.what() << std::endl;
    }
	return 0;
}

