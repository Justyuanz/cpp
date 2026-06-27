#include"iter.hpp"
#include<array>
#include<string>
#include<iostream>

int	main(void)
{
	std::cout << "------------------- int and const int -----------------" << std::endl;
	int intArr[3] = {2, 1, 3};
	::iter(intArr, std::size(intArr), print<int>);
	::iter(intArr, std::size(intArr), increase<int>);
	const int constInt[3] = {1, 2, 3};
	::iter(constInt, std::size(constInt), print<const int>);

	std::cout << "------------------- double and const double -----------------" << std::endl;
	double doubleArr[2] = {3.14, 4.25};
	::iter(doubleArr, std::size(doubleArr), print<double>);
	::iter(doubleArr, std::size(doubleArr), increase<double>);
	const double constDouble[2] = {3.14, 4.25};
	::iter(constDouble, std::size(constDouble), print<const double>);

	//float double char string bool
	std::cout << "------------------- char and const char -----------------" << std::endl;
	char charArr[4] = {'Y', 'U', 'A', 'N'};
	::iter(charArr, std::size(charArr), print<char>);
	::iter(charArr, std::size(charArr), increase<char>);
	const char constChar[3] = {'A', 'B', 'C'};
	::iter(constChar, std::size(constChar), print<const char>);

	std::cout << "------------------- str and const str -----------------" << std::endl;
	std::string strArr[2] = {"HEY", "YOU"};
	::iter(strArr, std::size(strArr), print<std::string>);
	::iter(strArr, std::size(strArr), print<std::string>);
	const std::string constStrArr[3] = {"alpha", "beta", "gamma"};
	::iter(constStrArr, std::size(constStrArr), print<const std::string>);

	std::cout << "------------------- bool and const bool -----------------" << std::endl;
	bool boolArr[4] = {true, false, true, false};
	::iter(boolArr, std::size(boolArr), print<bool>);
	const bool constBool[3] = {true, false, true};
	::iter(constBool, std::size(constBool), print<const bool>);
}

