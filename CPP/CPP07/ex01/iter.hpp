#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void callElement(const T& elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void iter(T* address, unsigned int len, void(*f)(const T& elem))
{
	for (unsigned int i = 0; i < len; i++)
		f(address[i]);
}

#endif