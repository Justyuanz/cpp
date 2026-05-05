# ifndef DOG_HPP
#define DOG_HPP

#include"AAnimal.hpp"
#include"Brain.hpp"
class Dog : public AAnimal
{
	private:
	Brain *_brain;
	public:
	Dog();
	~Dog();

	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	void makeSound() const;
	void setIdea(int i, const std::string &s);
	const std::string &getIdea(int i) const;
};
#endif
