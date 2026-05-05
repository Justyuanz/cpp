#include"AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(): _type("Animal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string &name): _type(name)
{
	std::cout << "AAnimal constructor called with type: " << _type << std::endl;
}
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	if (this != &other)
		this->_type = other._type;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string AAnimal::getType() const
{
	return (_type);
}
