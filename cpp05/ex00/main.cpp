#include"Bureaucrat.hpp"
#include<iostream>
int main(void)
{
	{
		Bureaucrat a("John", 2);
		Bureaucrat b("Amy", 150);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		try
		{
			a.incrementGrade();
			std::cout << a << std::endl;
			a.incrementGrade();
			std::cout << a <<std::endl;
			b.decrementGrade();
			std::cout << b << std::endl;
			b.decrementGrade();
			std::cout << b <<std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat:: GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		};
	}
	
	return (0);
}