#include "Zombie.hpp"
#include<iostream>

int main(void)
{
  	Zombie* horde = zombieHorde(5, "Horde");
  	if (!horde)
  		return (std::cout << "Error: Allocation fail." << std::endl, 1);
  	for (int i = 0; i < 5; ++i)
  		horde[i].announce();
  	delete[] horde;

  	Zombie* bad = zombieHorde(0, "Bad");
  	if (!bad)
  		return (std::cout << "Error: Allocation fail." << std::endl, 1);
  	delete[] bad;

	Zombie* badTwo = zombieHorde(99999999, "BadTwo");
  	if (!badTwo)
  		return (std::cout << "Error: Allocation fail." << std::endl, 1);
  	delete[] badTwo;
  	return (0);
}

