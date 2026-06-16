#pragma once

#include <algorithm>
/*
there is no universal type called:iterator
different containers have different iterator types:
std::vector<int>::iterator
std::list<int>::iterator
std::deque<int>::iterator
because T is a template type, we must write: 
typename T::iterator ("Compiler, T::iterator is a type. ")
*/
template <typename T>
typename T::iterator easyfind(T& container, int num)
{
	return std::find(container.begin(), container.end(), num);	
}