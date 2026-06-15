#include"Array.hpp"
#include <stdexcept>

//Array<T> NOW it's a concrete class (where T is the template parameter)
template <typename T>
Array<T>::Array():_arr(nullptr), _size(0)
{
};

template <typename T>
Array<T>::Array(unsigned int size):_arr(nullptr), _size(size)
{
	// each element is zero/default initialized
	// int   → 0
	// float → 0.0
	// char  → '\0'
	// class → default constructor called*/
	if (size > 0)
		_arr = new T[size];
}

template <typename T>
Array<T>::Array(const Array &other) : _arr(nullptr), _size(other._size)
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

	//prepare new memory FIRST, before touching anything
    T* new_arr = nullptr;
    if (other._size > 0)
    {
        new_arr = new T[other._size]; // if this throws, _arr is untouched
        for (unsigned int i = 0; i < other._size; i++)
            new_arr[i] = other._arr[i];
    }

    delete[] _arr;   //free old memory
    _arr = new_arr;  //point to new memory
    _size = other._size; // update size

    return *this;
}

template <typename T>
T& Array<T>::operator[](int index) const
{
    if (index < 0 || static_cast<unsigned int>(index) >= _size)
	{
        throw std::exception();
	}
	return _arr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}
