#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iosfwd>
#include <exception>

class Bureaucrat
{
	private:
	const std::string	_name; //A const member must be set at the moment of creation, cannot set it later.
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
		private:
		std::string	_msg;
		public:
		GradeTooHighException(const std::string &message);
		const char* what() const noexcept
		{
			return "GradeTooHigh";
		}
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char* what() const noexcept;
	};
};

//operator<< must be a free function, not a member: As a member function, the left side of << would have to be a Bureaucrat.
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif