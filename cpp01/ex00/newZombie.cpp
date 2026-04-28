#include "Zombie.hpp"
/*
new:
Calls malloc under the hood (allocates bytes)
Calls the constructor on those bytes
Returns pointer to the now-constructed object

delete:
Calls the destructor first
Calls free under the hood
*/
Zombie* newZombie(std::string name)
{
	Zombie	*new_zombie = NULL;
	try
	{
		new_zombie = new Zombie(name);
	}
	catch (...)
	{
		return (NULL);
	}
	return (new_zombie);
}