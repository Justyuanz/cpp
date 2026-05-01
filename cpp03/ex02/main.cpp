#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n===== CLAPTRAP TEST =====" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n===== SCAVTRAP TEST =====" << std::endl;
	ScavTrap scav("Scavvy");
	scav.attack("enemy");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << "\n===== FRAGTRAP CONSTRUCTOR TEST =====" << std::endl;
	FragTrap frag("Fraggy");

	std::cout << "\n===== FRAGTRAP BASIC ACTION TEST =====" << std::endl;
	frag.attack("enemy");
	frag.takeDamage(40);
	frag.beRepaired(20);
	frag.highFivesGuys();

	std::cout << "\n===== FRAGTRAP DEATH TEST =====" << std::endl;
	frag.takeDamage(200);
	frag.attack("enemy after death");
	frag.beRepaired(10);
	frag.highFivesGuys();

	std::cout << "\n===== FRAGTRAP ENERGY TEST =====" << std::endl;
	FragTrap tired("TiredFrag");
	for (int i = 0; i < 101; i++)
		tired.attack("dummy");

	std::cout << "\n===== COPY TEST =====" << std::endl;
	FragTrap copy(frag);
	copy.attack("copy target");
	copy.highFivesGuys();

	FragTrap assigned("AssignedBefore");
	assigned = tired;
	assigned.attack("assigned target");

	std::cout << "\n===== DESTRUCTOR ORDER TEST =====" << std::endl;
	return (0);
}