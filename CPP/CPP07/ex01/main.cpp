#include "iter.hpp"
#include <string>
// #include <cstdlib>

// void leaks()
// {
//     system("leaks template");
// }

int main (void)
{
	// atexit(leaks);
	int iArray[5] = {1, 2, 3, 4, 5};
	::iter<int>(iArray, 5, callElement);

	std::cout << "===============================" << std::endl;

	double dArray[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
	::iter<double>(dArray, 5, callElement);

	std::cout << "===============================" << std::endl;

	char cArray[5] = {'a', 'b', 'c', 'd', 'e'};
	::iter<char>(cArray, 5, callElement);

	std::cout << "===============================" << std::endl;
	
	std::string sArray[5] = {"hello", "my", "name", "is", "Template"};
	::iter<std::string>(sArray, 5, callElement);


}
