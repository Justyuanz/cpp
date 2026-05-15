#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const	std::string	_target;

protected:
	void	executeAction(const Bureaucrat &executor) const override;

public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other) = delete;
};