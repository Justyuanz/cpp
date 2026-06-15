#pragma once

//Array is NOT a class yet, it's a blueprint for making classes
template <typename T>
class Array
{
private:
	T*				_arr;
	unsigned int	_size;
public:
	Array();
	Array(unsigned int size);
	Array(const Array &other);
	~Array();

	Array&			operator=(const Array &other);
	T&				operator[](int index) const;
	unsigned int	size() const;
};

#include"Array.tpp"