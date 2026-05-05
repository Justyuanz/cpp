#include"Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}
Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

void Brain::setIdea(int i, const std::string &s)
{
	if (i < 0 || i >= 100)
		return;
	_ideas[i] = s;
}

const std::string &Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
		return(_ideas[0]);
	return (_ideas[i]);
}
