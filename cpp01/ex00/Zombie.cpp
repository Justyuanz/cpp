#include "Zombie.hpp"
#include <iostream>
Zombie::Zombie()
{
}

//: _name(name) — this is the initializer list. It initializes _name before the constructor body runs.
Zombie::Zombie(const std::string &name):_name(name)
{
}

Zombie::~Zombie()
{
}
//const at the end means this method promises not to modify the object.
void Zombie::announce() const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
