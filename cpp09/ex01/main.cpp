#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        try
        {
            RPN rpn;
            std::cout << rpn.calculate(argv[1]) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }

        return 0;
    }

    std::cerr << "Usage: ./RPN RPN" << std::endl;
    return 1;
}