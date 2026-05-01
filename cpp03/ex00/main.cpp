#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\n===== CONSTRUCTOR TEST =====" << std::endl;
	ClapTrap a("Clap");

	std::cout << "\n===== BASIC ACTION TEST =====" << std::endl;
	a.attack("enemy");
	a.takeDamage(4);
	a.beRepaired(3);

	std::cout << "\n===== DEATH TEST =====" << std::endl;
	a.takeDamage(100);
	a.attack("enemy after death");
	a.beRepaired(10);

	std::cout << "\n===== ENERGY TEST =====" << std::endl;
	ClapTrap b("Tired");
	for (int i = 0; i < 11; i++)
		b.attack("dum");

	std::cout << "\n===== COPY TEST =====" << std::endl;
	ClapTrap c(a);
	ClapTrap d("Ori");
	d = b;

	std::cout << "\n===== DESTRUCTOR TEST =====" << std::endl;
	return (0);
}
