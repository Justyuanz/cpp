# ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie
{
	private:
		std::string	_name;
	public:
			Zombie();
			Zombie(const std::string &name);
			~Zombie();
			void announce(void) const;

};

void randomChump(std::string name);
Zombie* newZombie(std::string name);
#endif
