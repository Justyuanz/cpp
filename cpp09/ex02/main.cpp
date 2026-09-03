#include "PmergeMe.hpp"

#include <exception>
#include <iostream>

int main(int argc, char** argv)
{
    try
    {
        PmergeMe pmergeMe;
        pmergeMe.loadInput(argv, argc);
        pmergeMe.sortAndDisplay();
    }
    catch (const std::exception& error)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}
