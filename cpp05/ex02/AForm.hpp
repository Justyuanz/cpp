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

protected:
	virtual void executeAction(const Bureaucrat &executor) const = 0;

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

	class NotSignedException : public std::exception
	{
	public:
		const char* what() const noexcept
		{
			return "AForm: Not signed.";
		}
	};

	//Pass or return by reference, const to protect the original Pass ore return by value, no const needed, it's already a copy.
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &other);
	virtual ~AForm();

	AForm 				&operator=(const AForm &other);
	void				beSigned(Bureaucrat &b);
	void 				execute(Bureaucrat const & executor) const;
	//getters
	const std::string	&getName() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	bool				getIsSigned() const;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);
