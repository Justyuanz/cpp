#include<iostream>
#include"PhoneBook.hpp" 
int	main(void)
{
	PhoneBook phonebook;
	std::string	input;

	while (true)
	{
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		if (!std::getline(std::cin, input))
			break ;
		if (input != "ADD" && input != "SEARCH" && input != "EXIT" )
			std::cout << "Bad input" << std::endl;
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else
			break;
	}
	return (0);
}
