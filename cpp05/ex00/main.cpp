#include"Bureaucrat.hpp"
#include<iostream>
int main(void)
{
	{
		Bureaucrat a("John", 2);
		Bureaucrat b("Amy", 150);

		std::cout << a << std::endl;
		std::cout << b << std::endl;

	return (0);
}