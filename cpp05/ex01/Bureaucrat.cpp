#include"Bureaucrat.hpp"
#include "Form.hpp"
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
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
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

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << _name << " couldn't sign " << f.getName()
		<< " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}
