#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const	std::string	_target;

protected:
	void	executeAction() const override;

public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &other) = delete;
};