#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n-- Rule of 3 --" << std::endl;
	ScavTrap a("Sentinel");
	ScavTrap b(a);
	ScavTrap c("Ben");
	c = a;

	std::cout << "\n-- Basic actions --" << std::endl;
	a.attack("intruder");
	a.guardGate();
	b.attack("intruder");
	b.guardGate();

	std::cout << "\n-- Damage and repair --" << std::endl;
	c.takeDamage(30);
	c.beRepaired(10);
	c.takeDamage(200);  // should drop to 0
	c.beRepaired(5);    // should be blocked

	std::cout << "\n-- Energy exhaustion --" << std::endl;
	ScavTrap worker("Worker");
	for (int i = 0; i < 52; ++i)
		worker.attack("target"); // should block after EP is 0

	return (0);
}

