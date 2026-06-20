#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"Intern.hpp"
#include<iostream>
int main(void)
{
	Intern someRandomIntern;
	Bureaucrat alice("Alice", 1);
	AForm* form;

	std::cout << "------- shrubbery form test--------" << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "garden");
	alice.signAForm(*form); //get the actual AForm object
	alice.executeForm(*form);
	delete form;

	std::cout << "------- robotomy form test--------" << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	alice.signAForm(*form);
	alice.executeForm(*form);
	delete form;

	std::cout << "------- presidential form test--------" << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Bob");
	alice.signAForm(*form);
	alice.executeForm(*form);
	delete form;

	std::cout << "------- unsigned form execute test--------" << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "unsigned_garden");
	alice.executeForm(*form);
	delete form;

	std::cout << "------- invalid form test--------" << std::endl;
	try
	{
		form = someRandomIntern.makeForm("does not exist", "target");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
