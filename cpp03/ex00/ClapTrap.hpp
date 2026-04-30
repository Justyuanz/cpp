# ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include<string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints = 10;
		unsigned int	_energyPoints = 10;
		unsigned int	_attackDamage = 0;		
	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		~ClapTrap();

		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif