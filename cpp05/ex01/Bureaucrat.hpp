#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iosfwd>
#include <exception>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	// Orthodox Canonical Form
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

#endif