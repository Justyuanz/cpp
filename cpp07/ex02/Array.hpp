#pragma once

#include <exception>

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
	T&				operator[](int index);
	const T&		operator[](int index) const;
	unsigned int	size() const;
};

template <typename T>
Array<T>::Array(): _arr(nullptr), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int size): _arr(nullptr), _size(size)
{
	if (size > 0)
		_arr = new T[size]();
}

template <typename T>
Array<T>::Array(const Array &other): _arr(nullptr), _size(other._size)
{
	if (_size > 0)
	{
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = other._arr[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this == &other)
		return *this;
	T* new_arr = nullptr;
	if (other._size > 0)
	{
		new_arr = new T[other._size];
		for (unsigned int i = 0; i < other._size; i++)
			new_arr[i] = other._arr[i];
	}
	delete[] _arr;
	_arr = new_arr;
	_size = other._size;
	return *this;
}

template <typename T>
T& Array<T>::operator[](int index)
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw std::exception();
	return _arr[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw std::exception();
	return _arr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
