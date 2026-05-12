#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include<iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
AForm("ShrubberyCreationForm", 145, 137),
_target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
AForm(other),
_target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	/*
	Creates a file <target>_shrubbery in the working directory
	and writes ASCII trees inside it
	*/

	(void)executor;
	std::cout << "execute override." << std::endl;
}
