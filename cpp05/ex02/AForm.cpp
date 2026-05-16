#include"AForm.hpp"
#include"Bureaucrat.hpp"
#include<iostream>

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute):
_name(name),
_gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	_isSigned = false;
}

AForm::AForm(const AForm &other):
_name(other._name),
_gradeToSign(other._gradeToSign),
_gradeToExecute(other._gradeToExecute)
{
	_isSigned = other._isSigned;
}
AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &other) //const members can only be initialized, not assigned. They  can be set in a constructor initializer list.
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

const std::string &AForm::getName() const
{
	return _name;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _gradeToSign)
	{
		_isSigned = true;
		return ;
	}
	throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw NotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute()
		<< ", is signed or not: " << f.getIsSigned();
	return out;
}
