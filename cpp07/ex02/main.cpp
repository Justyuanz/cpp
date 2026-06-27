#include <iostream>
#include <string>
#include "Array.hpp"

int	main(void)
{
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
	Array<int> numbers(5);
	std::cout << "numbers size: " << numbers.size() << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;

	std::cout << "numbers values: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "copy constructor" << std::endl;
	Array<int> copy(numbers);
	std::cout << "copy size: " << copy.size() << std::endl;

	bool same = true;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		if (copy[i] != numbers[i])
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
		numbers[numbers.size()] = 0;
		std::cout << "numbers[size] did not throw" << std::endl;
	}
	catch (const std::exception &)
	{
		std::cout << "numbers[size] threw an exception" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "string array" << std::endl;
	Array<std::string> words(3);
	words[0] = "hello";
	words[1] = "hi";
	words[2] = "world";

	std::cout << "words values: ";
	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << words[i] << " ";
	std::cout << std::endl;

	Array<std::string> wordsCopy(words);
	words[0] = "changed";
	if (wordsCopy[0] != words[0])
		std::cout << "string copy is independent" << std::endl;
	else
		std::cout << "string copy is not independent" << std::endl;
	return 0;
}
