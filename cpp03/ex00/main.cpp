#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Alpha");
	ClapTrap b("Beta");
	ClapTrap c(a);
	b = a;

	a.attack("Beta");
	b.takeDamage(3);
	b.beRepaired(2);
	b.takeDamage(50);
	b.attack("Alpha");   // blocked (dead)
	return (0);
}
