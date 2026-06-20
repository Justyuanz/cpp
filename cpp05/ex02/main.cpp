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

	std::cout << "------- print check--------" << std::endl;
	std::cout << alice << std::endl;
	std::cout << bob << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	std::cout << "------- shrubbery sign / execute--------" << std::endl;
	alice.signAForm(a); //ShrubberyCreationForm
	try
	{
		alice.executeForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "------- robotomy sign / execute--------" << std::endl;
	alice.signAForm(c);
	try
	{
		alice.executeForm(c);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout <<  "------- pardon sign / execute--------" << std::endl;
	alice.signAForm(d);
	try
	{
		alice.executeForm(d);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "------- unsigned form execute--------" << std::endl;
	try
	{
		alice.executeForm(unsignedForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "------- low grade execute check--------" << std::endl;
	try
	{
		bob.executeForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	 
	std::cout << "------- low grade bureaucrat checks--------" << std::endl;
	try
  	{
		bob.signAForm(d); // d needs sign grade 25, bob is 150
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
