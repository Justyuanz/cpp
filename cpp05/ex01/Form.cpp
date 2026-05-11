#include"Form.hpp"
#include"Bureaucrat.hpp"
#include<iostream>

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute):
_name(name),
_gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	_isSigned = false;
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &other):
_name(other._name),
_gradeToSign(other._gradeToSign),
_gradeToExecute(other._gradeToExecute)
{
	_isSigned = other._isSigned;
	std::cout << "Form copy constructor called" << std::endl;
}
Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &other) //const members can only be initialized, not assigned. They  can be set in a constructor initializer list.
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

const std::string &Form::getName() const
{
	return _name;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
		return ;
	}
	throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.getName()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute()
		<< ", is signed or not: " << f.getIsSigned();
	return out;
}