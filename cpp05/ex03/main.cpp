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

    // test 1 — valid form
    form = someRandomIntern.makeForm("shrubbery creation", "garden");
    alice.signAForm(*form);
    alice.executeForm(*form);
    delete form;

    // test 2 — valid form
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    delete form;

    // test 3 — valid form
    form = someRandomIntern.makeForm("presidential pardon", "Bob");
    delete form;

    // test 4 — invalid form name
    try
    {
        form = someRandomIntern.makeForm("does not exist", "target");
        delete form;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
