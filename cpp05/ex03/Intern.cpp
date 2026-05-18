#include"Intern.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
#include<stdexcept>
#include<iostream>

static AForm *createShrubbery(const std::string &t)
{ 
	return new ShrubberyCreationForm(t);
}

static AForm *createRobotomy(const std::string &t)
{ 
	return new RobotomyRequestForm(t);
}

static AForm *createPardon(const std::string &t)
{ 
	return new PresidentialPardonForm(t);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) const
{
	std::string forms[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(*creators[])(const std::string &t) = 
	{
		createShrubbery, // just the name = pointer to the function
		createRobotomy,
		createPardon
	};
	for (size_t i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout <<  "Intern creates " << formName << std::endl;
			return creators[i](formTarget);
		}
	}

	throw std::runtime_error("Form '" + formName + "' does not exist");
}
