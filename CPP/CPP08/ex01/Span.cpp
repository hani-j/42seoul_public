#include "Span.hpp"

Span::Span() {}
Span::Span(unsigned int maxN) : _maxN(maxN) {}
Span::~Span() {}
Span::Span(const Span& obj) : _maxN(obj._maxN), _vec(obj._vec) {}
Span& Span::operator=(const Span& obj) 
{
	if (this != &obj)
	{
		_maxN = obj._maxN;
		_vec = obj._vec;
	}
	return (*this);
}

void Span::addNumber(int num)
{
	if (_vec.size() >= _maxN)
		throw FullVecException();
	_vec.push_back(num);
}
unsigned int Span::shortestSpan() const
{
	if (_vec.size() < 2)
		throw NoFoundException();
	std::vector<int> vec(_vec);
	std::vector<int> diff(_vec);
	std::sort(vec.begin(), vec.end());
	std::adjacent_difference(vec.begin(), vec.end(), diff.begin());
	std::sort(diff.begin() + 1, diff.end());
	return (diff[1]);
}
unsigned int Span::longestSpan() const
{
	if (_vec.size() < 2)
		throw NoFoundException();
	return (*std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end()));
}
void Span::fillElem(unsigned int num)
{
	if (_maxN < num + _vec.size())
		throw FullVecException();
	for (unsigned int i = 0; i < num; i++)
	{
		_vec.push_back(i);
	}
}
