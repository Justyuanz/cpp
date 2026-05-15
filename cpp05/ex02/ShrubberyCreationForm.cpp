#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include<fstream>
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

void ShrubberyCreationForm::executeAction(const Bureaucrat &executor) const
{
	(void)executor;
	int	ivalue = 0;

	try
    {
		std::ofstream	myFile(_target + "_shrubbery");
		myFile.exceptions(std::ifstream::failbit);
		myFile << ivalue; // may throw
    }
    catch (const std::ios_base::failure& fail)
    {
        std::cerr << fail.what() << '\n';
    }
}
