#include"Easyfind.hpp"
#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<forward_list>

template <typename T>
void test_easyfind(T& container, int num)
{
	typename T::iterator it = easyfind(container, num);
	if (it != container.end())
		std::cout << "Found:" << *it << std::endl;
	else
		std::cout << "Not found." << std::endl; 
}

int main(void)
{
	{
		std::cout << "--------------test vector-------------" << std::endl;
		std::vector<int> vec = {0, 1, 2, 3, 4};
		test_easyfind(vec, 0);
		test_easyfind(vec, 99);
	}
	{
		std::cout << "--------------test list-------------" << std::endl;
		std::list<int> list = {0, 1, 2, 3, 4};
		test_easyfind(list, 0);
		test_easyfind(list, 99);
	}
	{
		std::cout << "--------------test list-------------" << std::endl;
		std::list<int> list = {0, 1, 2, 3, 4};
		test_easyfind(list, 0);
		test_easyfind(list, 99);
	}
	{
		std::cout << "--------------test deque-------------" << std::endl;
		std::deque<int> de = {0, 1, 2, 3, 4};
		test_easyfind(de, 0);
		test_easyfind(de, 99);
	}
	{
		std::cout << "--------------test forward list-------------" << std::endl;
		std::forward_list<int> f_list = {0, 1, 2, 3, 4};
		test_easyfind(f_list, 0);
		test_easyfind(f_list, 99);
	}
}