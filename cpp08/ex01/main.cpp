#include "Span.hpp"
#include <exception>
#include <iostream>

int main()
{
	Span sp = Span(5);
    try
    {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

    }
    catch (std::exception &e)
    {
		std::cerr << e.what() << std::endl;
    }

	sp.printNumbers();
    std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span: " << sp.longestSpan() << std::endl;
    return 0;
}
