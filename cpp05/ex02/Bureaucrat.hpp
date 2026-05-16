#pragma once

#include <string>
#include <iosfwd>
#include <exception>

class AForm;
class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	// Orthodox Canonical AForm
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	// getters
	int					getGrade() const;
	const std::string	&getName() const;

	// actions
	void incrementGrade();
	void decrementGrade();
	void signAForm(AForm &AForm);
	void executeForm(AForm const &form) const;

	//exceptions,nested inside Bureaucrat — they belong to Bureaucrat, not standalone classes.
	class GradeTooHighException: public std::exception
	{
	public:
		const char* what() const noexcept
		{
			return "GradeTooHigh";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const noexcept
		{
			return "GradeTooLow";
		}
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);
