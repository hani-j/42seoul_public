#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <numeric>

class Span
{
	private:
		unsigned int _maxN;
		std::vector<int> _vec;
		Span();
	public:
		Span(unsigned int maxN);
		Span(const Span& obj);
		~Span();
		Span& operator=(const Span& obj);

		void addNumber(int num);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		void fillElem(unsigned int num);
};

class FullVecException : public std::exception
{
	public :
		const char* what() const throw()
		{
			return ("already max number elements stored");
		}
};

class NoFoundException : public std::exception
{
	public :
		const char* what() const throw()
		{
			return ("no span can be found");
		}
};

#endif
