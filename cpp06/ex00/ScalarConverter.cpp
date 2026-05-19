#include"ScalarConverter.hpp"
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<limits>
#include<cmath>
#include<cerrno>

static inline bool isCharLiteral(const std::string &input)
{
	return input.length() == 3 && input[0] == '\'' && input[2] == '\'';
}

static bool isFloatLiteral(const std::string &input)
{
	if (input[input.length() - 1] != 'f')
		return false;
	if (input.find('.') == std::string::npos)
		return false;
	std::string trim = input.substr(0, input.length() - 1);
	char *end = NULL;
	std::strtod(trim.c_str(), &end);
	if (*end != '\0' || errno == ERANGE)
		return false;
	return true;
}

static bool isDoubleLiteral(const std::string &input)
{
	if (input.find('.') == std::string::npos)
		return false;
	char *end = NULL;
	std::strtod(input.c_str(), &end);
	if (*end != '\0' || errno == ERANGE)
		return false;
	return true;
}

static bool isIntLiteral(const std::string &input)
{
	errno = 0;
	char *end = NULL;
	std::strtol(input.c_str(), &end, 10);
	if (*end != '\0' || errno == ERANGE)
		return false;
	return true;
}

static inline bool isPseudoFloat(const std::string &input)
{
    return input == "nanf" || input == "+inff" || input == "-inff";
}

static inline bool isPseudoDouble(const std::string &input)
{
    return input == "nan" || input == "+inf" || input == "-inf";
}

static double getPseudoValue(const std::string &input)
{
	if (input == "nan" || input == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	if (input == "+inf" || input == "+inff")
		return std::numeric_limits<double>::infinity();
	return -std::numeric_limits<double>::infinity();
}

static void displayChar(double value)
{
	std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value)
		|| value < std::numeric_limits<char>::min()
    	|| value > std::numeric_limits<char>::max())
        std::cout << "impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(static_cast<char>(value))))
        std::cout << "Non displayable\n";
	else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void displayInt(double value)
{
	std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value)
		|| value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max())
        std::cout << "impossible\n";
	else
        std::cout << static_cast<int>(value) << std::endl;
}

static void displayFloat(double value)
{
	float f = static_cast<float>(value);
	std::cout << "float: ";
	if (std::isnan(f))
    	std::cout << "nanf" << std::endl;
	else if (std::isinf(f))
    	std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
	else if (value < std::numeric_limits<float>::lowest()
		|| value > std::numeric_limits<float>::max())
        std::cout << "impossible\n";
	else
        std::cout << std::fixed << std::setprecision(1)<< f << "f" << std::endl;
}

static void displayDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
  		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
    	std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else if (value < std::numeric_limits<double>::lowest()
		|| value > std::numeric_limits<double>::max())
        std::cout << "impossible\n";
	else
        std::cout << std::fixed << std::setprecision(1)<< value << std::endl;
}

static void displayInvalid()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string &input)
{
	if (input.empty())
	{
		std::cout << "Error: invalid input" << std::endl;
		return ;
	}

	double value = 0.0;
	if (isPseudoFloat(input) || isPseudoDouble(input))
		value = getPseudoValue(input);
	else if (isCharLiteral(input))
		value = static_cast<double>(input[1]);
	else if (isFloatLiteral(input))
		value = std::strtod(input.substr(0, input.length() - 1).c_str(), NULL);
	else if (isDoubleLiteral(input))
		value = std::strtod(input.c_str(), NULL);
	else if (isIntLiteral(input))
		value = std::strtol(input.c_str(), NULL, 10);
	else
	{
		displayInvalid();
		return;
	}

	displayChar(value);
	displayInt(value);
	displayFloat(value);
	displayDouble(value);
}

