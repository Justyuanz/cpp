#include"Bureaucrat.hpp"
#include"Form.hpp"
#include<iostream>

int main(void)
{
	Form a("alice", 25, 2);

	std::cout << a << std::endl;

	return 0;
}