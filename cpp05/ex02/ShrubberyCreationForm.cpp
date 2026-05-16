#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include<fstream>

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

void ShrubberyCreationForm::executeAction() const
{
	//std::ofstream f("/no_such_dir/x_shrubbery");
	std::ofstream	myFile(_target + "_shrubbery");
	
	if(!myFile.is_open())
        throw std::ios_base::failure("ShrubberyCreationForm: cannot open file");
	for (size_t i = 0; i < 3; i++)
	{
		myFile << "       _-_\n";
		myFile << "    /~~   ~~\\\n";
		myFile << " /~~         ~~\\\n";
		myFile << "{               }\n";
		myFile << " \\  _-     -_  /\n";
		myFile << "   ~  \\\\ //  ~\n";
		myFile << "_- -   | | _- _\n";
		myFile << "  _ -  | |   -_\n";
		myFile << "      // \\\\\n";
		myFile << '\n';
	}
}
