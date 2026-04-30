#include<iostream>
#include<string>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]);
		for (size_t j = 0; j < str.length(); j++)
		{
			char c = av[i][j];
			if (c >= 'a' && c <= 'z')
				c = c - 'a' + 'A';
			std::cout << c;
		}
	}
	std::cout << std::endl;
	return (0);
}