#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap("ScavDefault")// call base constructor FIRST
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string &name): ClapTrap(name) // only own members/base classes go here.
{
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other); //this always refers to the object the function is called on, not the class
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
  	{
  		std::cout << "ScavTrap " << _name << " can't do anything." << std::endl;
  		return;
  	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!"
			<< std::endl;
}

void ScavTrap::guardGate(void)
{
  	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

