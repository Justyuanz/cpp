#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n-- Rule of 3 --" << std::endl;
	FragTrap a("FragA");
	FragTrap b(a);
	FragTrap c("FragC");
	c = a;

	std::cout << "\n-- Basic actions --" << std::endl;
	a.attack("intruder");
	a.highFivesGuys();
	b.attack("intruder");
	b.highFivesGuys();

	std::cout << "\n-- Damage and repair --" << std::endl;
	c.takeDamage(30);
	c.beRepaired(10);
	c.takeDamage(200);  // should drop to 0 for FragTrap
	c.beRepaired(5);    // should be blocked

	std::cout << "\n-- Energy exhaustion --" << std::endl;
	FragTrap worker("Worker");
	for (int i = 0; i < 102; ++i)
		worker.attack("target"); // should block after EP is 0

	return (0);
}
