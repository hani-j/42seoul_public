#include "Span.hpp"
// #include <cstdlib>

// void leaks()
// {
//     system("leaks span");
// }

int main(void)
{
	// atexit(leaks);
	Span span(5);
	try
	{
		std::cout << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	span.addNumber(1);
	span.addNumber(3);
	span.addNumber(42);
	span.addNumber(70);
	span.addNumber(13);
	try
	{
		span.addNumber(13);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;

	Span span2(100000);
	span2.fillElem(100000);
	std::cout << span2.shortestSpan() << std::endl;
	std::cout << span2.longestSpan() << std::endl;
}
