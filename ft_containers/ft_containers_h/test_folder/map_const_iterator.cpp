#include "../map.hpp"
#include <map>
#include <iostream>
int main()
{
	{
		std::map<char, int> m;
		m['a'] = 1;

		std::map<char, int>::iterator it;
		it = m.begin();
		std::cout << (*it).second << std::endl;
		std::map<char, int>::iterator it2(it);
		std::cout << (*it2).second << std::endl;

		std::map<char, int>::const_iterator cit;
		cit = m.begin();
		std::cout << (*cit).second << std::endl;
		// std::map<char, int>::iterator cit2(cit);
		// std::cout << (*cit2).second << std::endl;
		}
	{
		ft::map<char, int> m;
		m['a'] = 1;

		ft::map<char, int>::iterator it;
		it = m.begin();
		std::cout << (*it).second << std::endl;
		ft::map<char, int>::iterator it2(it);
		std::cout << (*it2).second << std::endl;

		ft::map<char, int>::const_iterator cit;
		cit = m.begin();
		std::cout << (*cit).second << std::endl;
		ft::map<char, int>::iterator cit2(cit);
		std::cout << (*cit2).second << std::endl;
	}
}