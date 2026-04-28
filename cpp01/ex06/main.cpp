#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
  	if (argc != 2)
  		return (std::cout << "Usage: ./harlFilter <LEVEL>" << std::endl, 1);
  	Harl h;

  	h.complain(argv[1]);
  	return (0);
}