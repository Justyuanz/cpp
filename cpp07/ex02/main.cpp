#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int	main(void)
{
	std::srand(std::time(NULL));

	std::cout << "default constructor" << std::endl;
	Array<int> empty;
	std::cout << "empty size: " << empty.size() << std::endl;

	try
	{
		empty[0] = 42;
		std::cout << "empty[0] did not throw" << std::endl;
	}
	catch (const std::exception &)
	{
		std::cout << "empty[0] threw an exception" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "sized constructor" << std::endl;
	Array<int> numbers(MAX_VAL);
	std::cout << "numbers size: " << numbers.size() << std::endl;

	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = std::rand();

	int *mirror = new int[MAX_VAL];
	for (unsigned int i = 0; i < MAX_VAL; i++)
		mirror[i] = numbers[i];

	std::cout << std::endl;
	std::cout << "copy constructor" << std::endl;
	Array<int> copy(numbers);
	std::cout << "copy size: " << copy.size() << std::endl;

	bool same = true;
	for (unsigned int i = 0; i < MAX_VAL; i++)
	{
		if (copy[i] != mirror[i])
			same = false;
	}
	if (same)
		std::cout << "copy has the same values" << std::endl;
	else
		std::cout << "copy does not match" << std::endl;

	numbers[0] = 123456;
	if (copy[0] != numbers[0])
		std::cout << "copy is independent" << std::endl;
	else
		std::cout << "copy is not independent" << std::endl;

	std::cout << std::endl;
	std::cout << "assignment operator" << std::endl;
	Array<int> assigned;
	assigned = numbers;
	std::cout << "assigned size: " << assigned.size() << std::endl;

	same = true;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		if (assigned[i] != numbers[i])
			same = false;
	}
	if (same)
		std::cout << "assignment copied the values" << std::endl;
	else
		std::cout << "assignment did not copy correctly" << std::endl;

	assigned[1] = 654321;
	if (assigned[1] != numbers[1])
		std::cout << "assignment is independent" << std::endl;
	else
		std::cout << "assignment is not independent" << std::endl;

	std::cout << std::endl;
	std::cout << "bounds checking" << std::endl;
	try
	{
		numbers[-1] = 0;
		std::cout << "numbers[-1] did not throw" << std::endl;
	}
	catch (const std::exception &)
	{
		std::cout << "numbers[-1] threw an exception" << std::endl;
	}

	try
	{
		numbers[MAX_VAL] = 0;
		std::cout << "numbers[MAX_VAL] did not throw" << std::endl;
	}
	catch (const std::exception &)
	{
		std::cout << "numbers[MAX_VAL] threw an exception" << std::endl;
	}

	delete[] mirror;
	return 0;
}
