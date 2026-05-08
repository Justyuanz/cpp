#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	bool				_isSigned;
public:
	//custom exception classes
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const noexcept
		{
			return "Form: Grade too high.";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const noexcept
		{
			return "Form: Grade too low.";
		}
	};

	//Pass or return by reference, const to protect the original Pass ore return by value, no const needed, it's already a copy.
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	Form(const Form &other);
	~Form();

	Form 				&operator=(const Form &other);
	beSigned();
	//getters
	const std::string	&getName() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	bool				getIsSigned() const;
};

std::ostream &operator<<(std::ostream &out, const Form &f);
