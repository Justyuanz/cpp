#include"Animal.hpp"
#include <iostream>

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &name): _type(name)
{
	std::cout << "Animal constructor called with type: " << _type << std::endl;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	if (this != &other)
		*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Some generic animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}
