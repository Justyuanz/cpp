#pragma once

#include<cstdlib>

template<typename T>
void increase(T &x);

template<typename T>
void print(const T &x);

template<typename T, typename F>
void iter(T *array, size_t length, F func);

template<typename T, typename F>
void iter(const T *array, size_t length, F func);

#include "iter.tpp"
