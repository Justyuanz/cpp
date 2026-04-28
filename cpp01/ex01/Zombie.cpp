#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}
void Zombie::setZombieName(const std::string &name)
{
	_name = name;
}

void Zombie::announce(void) const
{
	std::cout << _name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}


