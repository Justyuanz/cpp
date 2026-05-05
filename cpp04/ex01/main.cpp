#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	std::cout << "\n-- Brain creation/deletion --" << std::endl;
	{
		Dog d;
		Cat c;
	}

	std::cout << "\n-- Deep copy: copy constructor --" << std::endl;
	{
		Dog basic;
		basic.setIdea(0, "chase cats");
		{
			Dog tmp = basic;
			tmp.setIdea(0, "eat bones");
			std::cout << "basic: " << basic.getIdea(0) << " (should be chase cats)" << std::endl;
			std::cout << "tmp:   " << tmp.getIdea(0) << " (should be eat bones)" << std::endl;
		}
		std::cout << "basic survives: " << basic.getIdea(0) << std::endl;
	}

	std::cout << "\n-- Deep copy: assignment operator --" << std::endl;
	{
		Dog basic;
		basic.setIdea(0, "original");
		{
			Dog tmp;
			tmp = basic;
			tmp.setIdea(0, "different");
			std::cout << "basic: " << basic.getIdea(0) << " (must be 'original')" << std::endl;
			std::cout << "tmp:   " << tmp.getIdea(0) << " (must be 'different')" << std::endl;
		}
		std::cout << "basic survives: " << basic.getIdea(0) << std::endl;
	}

	std::cout << "\n-- Destruction chaining through Animal* --" << std::endl;
	{
		Animal *a = new Dog();
		Animal *b = new Cat();
		delete a;
		delete b;
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
