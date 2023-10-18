#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception
{
	public :
		const char* what() const throw()
		{
			return ("Not Found Value");
		};
};

template <typename T>
typename T::iterator easyfind(T& t, int i)
{
	typename T::iterator it;
	it = std::find(t.begin(), t.end(), i);
	if (it == t.end())
		throw NotFoundException();
	return (it);
}

#endif
