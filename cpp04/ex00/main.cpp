#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "\n-- Construction and destruction --" << std::endl;
	{
		Dog d;
		Cat c;
	}

	std::cout << "\n-- Polymorphism through Animal --" << std::endl;
	{
		Animal *a = new Dog();
		Animal *b = new Cat();
		Animal *c = new Animal();
		a->makeSound();
		b->makeSound();
		c->makeSound();
		delete a;
		delete b;
		delete c;
	}

	std::cout << "\n-- WrongAnimal: no virtual --" << std::endl;
	{
		WrongAnimal *a = new WrongCat();
		a->makeSound();
		delete a;
	}

	std::cout << "\n-- Array half Dog half Cat --" << std::endl;
	{
		const int N = 10;
		Animal *animals[N];
		for (int i = 0; i < N / 2; i++)
			animals[i] = new Dog();
		for (int i = N / 2; i < N; i++)
			animals[i] = new Cat();
		for (int i = 0; i < N; i++)
			animals[i]->makeSound();
		for (int i = 0; i < N; i++)
			delete animals[i];
	}

	return (0);
}