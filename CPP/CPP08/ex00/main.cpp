#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main(void)
{
	std::vector<int> container;
	std::vector<int>::iterator it;
	// std::deque<int> container;
	// std::deque<int>::iterator it;
	// std::list<int> container;
	// std::list<int>::iterator it;
	
	container.push_back(1);
	container.push_back(2);
	container.push_back(3);
	try
	{	
		it = easyfind(container, 3);
		std::cout << "find : " << *it << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		it = easyfind(container, 5);
		std::cout << "find : " << *it << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
