#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie *horde = NULL;
	try
	{
		horde = new Zombie[N];
	}
	catch(...)
	{
		return (NULL);
	}
	for (int i = 0; i < N; ++i)
  		horde[i].setZombieName(name);
  	return (horde);
}