#pragma once

#include <string>
class Form
{
private:
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	bool				_isSigned;
public:
	Form();
	Form(const Form &other);
	~Form();

	Form &operator=(const Form &other);
	class
};