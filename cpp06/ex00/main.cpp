#include"ScalarConverter.hpp"
#include<iostream>

int main(int ac, char **av)
{
	if (ac != 2)
    {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
	ScalarConverter::convert(av[1]);

	/*
	std::cout << "char min:   " << std::numeric_limits<char>::min() << std::endl;
    std::cout << "char max:   " << std::numeric_limits<char>::max() << std::endl;
	std::cout << "int min:    " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "int max:    " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "float min:  " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "float max:  " <<  std::numeric_limits<float>::max() << std::endl;
	std::cout << "double min: " <<  std::numeric_limits<double>::min() << std::endl;
    std::cout << "double max: " <<  std::numeric_limits<double>::max() << std::endl;

	double nanValue = std::numeric_limits<double>::quiet_NaN();
    double infValue = std::numeric_limits<double>::infinity();
    double negInfValue = -std::numeric_limits<double>::infinity();
    std::cout << "nanValue: " << nanValue << std::endl;
    std::cout << "infValue: "<< infValue << std::endl;
    std::cout << "negInfValue:"<< negInfValue << std::endl;

	double max = std::numeric_limits<double>::max();
    double inf = std::numeric_limits<double>::infinity();
    if (inf > max)
        std::cout << "inf: " << inf << " is greater than max: " << max << '\n';
	*/
}