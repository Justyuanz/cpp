#include"Cat.hpp"
#include<iostream>

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	_brain = new Brain();
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat &other): Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*other._brain);
				//        ^
				//        this is a Brain object being passed to Brain constructor
				//        C++ sees: Brain constructor receiving a Brain object
				//        C++ calls: Brain copy constructor automatically
}
Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*(this->_brain) = *(other._brain);
	}
	return(*this);
}

void Cat::makeSound() const 
{ 
	std::cout << "Meow~" << std::endl; 
}

void Cat::setIdea(int i, const std::string &s)
{
	if (i < 0 || i >= 100)
		return;
	_brain->setIdea(i, s);
}

const std::string &Cat::getIdea(int i) const
{
	return (_brain->getIdea(i));
}
