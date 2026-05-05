# ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include<string>

class Animal
{
	protected:
	std::string	_type;
	public:
	Animal();
	Animal(const std::string &name);
	virtual ~Animal();

	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual void makeSound() const; //Adding virtual to the base class function tells C++: "Don't look at the pointer type, look at the ACTUAL object."
	std::string getType() const;
};

# endif
