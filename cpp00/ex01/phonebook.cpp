#include"PhoneBook.hpp"
#include<iostream>


PhoneBook::PhoneBook()
{
	_index = 0;
	_count = 0;
}

PhoneBook::~PhoneBook()
{
}

//std::cin.clear() resets stream error state after EOF/fail.
static bool	read_line(std::string &line)
{
	if (!std::getline(std::cin, line))
	{
		std::cin.clear();
		return (false);
	}
	return (true);
}

static bool	is_only_spaces(const std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!(input[i] == ' ' || input[i] == '\t'))
			return (false);
	}
	return (true);
}

static bool	is_only_digit(const std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!(input[i] >= '0' && input[i] <= '9'))
			return (false);
	}
	return (true);
}

void	PhoneBook::add_contact()
{
	std::string first_name;
	while (true)
	{
		std::cout << "First name: " << std::endl;
		if (!read_line(first_name))
			return ;
		if (!is_only_spaces(first_name))
		{
			_contact[_index].setFirstName(first_name);
			break;
		}
		std::cout << "Invalid first name" << std::endl;
	}

	std::string last_name;
	while (true)
	{
		std::cout << "Last name: " << std::endl;
		if (!read_line(last_name))
			return ;
		if (!is_only_spaces(last_name))
		{
			_contact[_index].setLastName(last_name);
			break;
		}
		std::cout << "Invalid last name" << std::endl;
	}

	std::string nick_name;
	while (true)
	{
		std::cout << "Nick name: " << std::endl;
		if (!read_line(nick_name))
			return ;
		if (!is_only_spaces(nick_name))
		{
			_contact[_index].setNickName(nick_name);
			break;
		}
		std::cout << "Invalid nick name" << std::endl;
	}

	std::string phone_number;
	while (true)
	{
		std::cout << "Phone number: " << std::endl;
		if (!read_line(phone_number))
			return ;
		if (is_only_digit(phone_number) && !is_only_spaces(phone_number))
		{
			_contact[_index].setPhoneNumber(phone_number);
			break;
		}
		std::cout << "Invalid phone number" << std::endl;
	}

	std::string dark_secret;
  	while (true)
  	{
  		std::cout << "Dark secret: " << std::endl;
  		if (!read_line(dark_secret))
  			return ;
  		if (!is_only_spaces(dark_secret))
  		{
  			_contact[_index].setDarkSecret(dark_secret);
  			break;
  		}
  		std::cout << "Invalid dark secret" << std::endl;
  	}
	_index = (_index + 1) % 8;
	if (_count < 8)
		_count ++;
}

static std::string format_column(const std::string &text)
{
	int			spaces;
	std::string spaceholder;

	if (text.length() > 10)
		return(text.substr(0, 9) + ".");
	spaces = 10 - text.length();
	while(spaces > 0)
	{
		spaceholder += ' ';
		spaces--;
	}
	return (spaceholder + text);
}

static std::string	index_to_string(int index)
{
	std::string	result;

	result += index + '0';
	return (result);
}

static bool is_valid_index(const std::string &input, int count)
{
	if (input.length() != 1)
		return (false);
	if (input[0] < '0' || input[0] > '7')
		return (false);
	if (input[0] - '0' >= count)
		return (false);
	return (true);
}

void	PhoneBook::search_contact()
{
	if (_count == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	std::cout << format_column("Index") << "|"
				<< format_column("First Name") << "|"
				<< format_column("Last Name") << "|"
				<< format_column("Nickname") << std::endl;
	for (int i = 0; i < _count; i++)
	{
		std::cout << format_column(index_to_string(i)) << "|"
			<< format_column(_contact[i].getFirstName()) << "|"
			<< format_column(_contact[i].getLastName()) << "|"
			<< format_column(_contact[i].getNickName()) << std::endl;
	}

	std::string input_index;
	while (true)
	{
		std::cout << "Enter index: " << std::endl;
		if (!read_line(input_index))
			return ;
		if (is_valid_index(input_index, _count))
		{
			int	 index = input_index[0] - '0';
			std::cout << "First name: " << _contact[index].getFirstName() << std::endl;
			std::cout << "Last name: " << _contact[index].getLastName() << std::endl;
			std::cout << "Nick name: " << _contact[index].getNickName() << std::endl;
			std::cout << "Phone number: " << _contact[index].getPhoneNumber() << std::endl;
			std::cout << "Dark secret: " << _contact[index].getDarkSecret() << std::endl;
			break;
		}
		std::cout << "Invalid index" << std::endl;
	}

}

