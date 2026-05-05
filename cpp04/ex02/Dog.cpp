#include"Dog.hpp"
#include<iostream>
Dog::Dog(): AAnimal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &other): AAnimal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
}
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		*(this->_brain) = *(other._brain);
	}
	return(*this);
}

void Dog::makeSound() const 
{ 
	std::cout << "Woof!" << std::endl; 
}

void Dog::setIdea(int i, const std::string &s)
{
	if (i < 0 || i >= 100)
		return;
	_brain->setIdea(i, s);
}

const std::string &Dog::getIdea(int i) const
{
	return (_brain->getIdea(i));
}
