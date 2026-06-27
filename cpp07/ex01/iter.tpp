#include <iostream>
#include <type_traits>

template<typename T>
void increase(T &x)
{
	x++;
	std::cout << "increase: " << x << std::endl;
}

template<typename T>
void print(const T &x)
{
	if (std::is_const_v<T>)
		std::cout << "const: " << x << std::endl;
	else
		std::cout << x << std::endl;
}

template<typename T, typename F>
void iter(T *array, const size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template<typename T, typename F>
void iter(const T *array, const size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}
