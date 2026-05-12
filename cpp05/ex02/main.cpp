#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include<iostream>
int main(void)
{
	Bureaucrat alice("Alice", 5);
	ShrubberyCreationForm a("ShrubberyCreationForm");
	ShrubberyCreationForm b(a);

	alice.signAForm(a);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}