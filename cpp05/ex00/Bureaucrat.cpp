#include"Bureaucrat.hpp"
#include<iostream>

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat parametric constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	//const member must use initializer list. it runs during construction, before the object is fully created
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if(this != &other)
		this->_grade = other._grade;
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string &Bureaucrat::getName() const
{
	return(_name);
}

//moves toward grade 1(best)
void  Bureaucrat::incrementGrade()
{
  	if (_grade <= 1)
  		throw GradeTooHighException();
	_grade--;
}

//moves toward grade 150 (worse rank)
void  Bureaucrat::decrementGrade()
{
  	if (_grade >= 150)
  		throw GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high (must be between 1 and 150)");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low (must be between 1 and 150)");
}
