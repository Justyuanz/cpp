#include"Bureaucrat.hpp"
#include<iostream>
int main(void)
{
	std::cout << "-------increment check--------" << std::endl;
	try
	{
		Bureaucrat a("Alice" , 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		//Bureaucrat destructor called
		//GradeTooHigh
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << '\n' << "-------decrement check--------" << std::endl;
	try
	{
		Bureaucrat a("Alice" , 149);
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << '\n' << "-------constructor check--------" << std::endl;
	try
	{
		Bureaucrat a("Alice" , 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat a("Alice" , 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << '\n' << "-------basic action check--------" << std::endl;
	try
	{
		Bureaucrat a("Alice" , 120);
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}