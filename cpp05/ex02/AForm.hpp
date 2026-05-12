#pragma once

#include <string>

class Bureaucrat;
//AForm is essentially a permission-controlled object
class AForm
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
			return "AForm: Grade too high.";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const noexcept
		{
			return "AForm: Grade too low.";
		}
	};

	//Pass or return by reference, const to protect the original Pass ore return by value, no const needed, it's already a copy.
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &other);
	~AForm();

	AForm 				&operator=(const AForm &other);
	void		beSigned(Bureaucrat &b);
	virtual void execute(Bureaucrat const & executor) const = 0;
	//getters
	const std::string	&getName() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	bool				getIsSigned() const;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);
