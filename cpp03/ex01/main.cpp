#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n===== CLAPTRAP TEST =====" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n===== SCAVTRAP CONSTRUCTOR TEST =====" << std::endl;
	ScavTrap scav("Scavvy");

	std::cout << "\n===== SCAVTRAP BASIC ACTION TEST =====" << std::endl;
	scav.attack("enemy");
	scav.takeDamage(30);
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << "\n===== SCAVTRAP DEATH TEST =====" << std::endl;
	scav.takeDamage(200);
	scav.attack("enemy after death");
	scav.beRepaired(10);
	scav.guardGate();

	std::cout << "\n===== SCAVTRAP ENERGY TEST =====" << std::endl;
	ScavTrap tired("TiredScav");
	for (int i = 0; i < 51; i++)
		tired.attack("dummy");

	std::cout << "\n===== COPY TEST =====" << std::endl;
	ScavTrap copy(scav);
	copy.attack("copy target");

	ScavTrap assigned("Assigned");
	assigned = tired;
	assigned.attack("assigned target");

	std::cout << "\n===== DESTRUCTOR ORDER TEST =====" << std::endl;
	return (0);
}