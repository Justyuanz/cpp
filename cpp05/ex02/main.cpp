#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
#include<iostream>

int main(void)
{
	Bureaucrat alice("Alice", 5);
	Bureaucrat bob("Bob", 150);
	ShrubberyCreationForm a("ShrubberyCreationForm");
	ShrubberyCreationForm b(a);
	RobotomyRequestForm c("RobotomyRequestForm");
	PresidentialPardonForm d("PresidentialPardonForm");
	ShrubberyCreationForm unsignedForm("unsigned_test");


	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	alice.signAForm(a);
	try
	{
		alice.executeForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	alice.signAForm(c);
	try
	{
		alice.executeForm(c);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	alice.signAForm(d);
	try
	{
		alice.executeForm(d);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		alice.executeForm(unsignedForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		bob.executeForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	 
	try
  	{
		bob.signAForm(d); // d needs sign grade 25, bob is 150
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	
}
