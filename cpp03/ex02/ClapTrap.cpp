#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called @" << this << std::endl;
}

ClapTrap::ClapTrap(const std::string &name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called for " << _name << " @" << this << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << _name << " @" << this << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called @" << this << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called @" << this << std::endl;
	if (this == &other)
		return(*this);
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
  	{
  		std::cout << "ClapTrap " << _name << " can't do anything." << std::endl;
  		return;
  	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!"
			<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
  	{
  		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
  		return;
  	}
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage, HP now " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0 || _energyPoints == 0)
  	{
  		std::cout << "ClapTrap " << _name << " can't do anything." << std::endl;
  		return;
  	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs " << amount
  			  << " HP, now " << _hitPoints << std::endl;
}
