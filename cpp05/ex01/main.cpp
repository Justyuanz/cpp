#include"Bureaucrat.hpp"
#include"Form.hpp"
#include<iostream>

int main(void)
{
	std::cout << '\n' << "------- form constructor check--------" << std::endl;
	try
	{
		Form formA("FormA", 2, 5);
		std::cout << formA << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form formA("FormA", 151, 5);
		std::cout << formA << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form formA("FormA", 2, 0);
		std::cout << formA << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << '\n' << "-------basic sign check--------" << std::endl;
	try
	{
		Bureaucrat	a("Alice" , 1);
		Form		f("formB", 5, 20);
		a.signForm(f);
		std::cout << a << std::endl;
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat	a("Alice" , 5);
		Form		f("formB", 5, 20);
		a.signForm(f);
		std::cout << a << std::endl;
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

		std::cout << '\n' << "-------sign failure check--------" << std::endl;
	try
	{
		Bureaucrat	a("Bob" , 10);
		Form		f("formC", 5, 20);
		a.signForm(f);
		std::cout << a << std::endl;
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat	a("Bob" , 6);
		Form		f("formC", 5, 1);
		a.signForm(f);
		std::cout << a << std::endl;
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}