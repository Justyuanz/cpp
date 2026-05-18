#include"AForm.hpp"
#include"RobotomyRequestForm.hpp"
#include<iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
AForm("RobotomyRequestForm", 72, 45),
_target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
AForm(other),
_target(other._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "RRRRRRR drilling noises RRRRRRR" << std::endl;
	std::srand(std::time(0)); // use current time as seed for random generator
    if (rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}
