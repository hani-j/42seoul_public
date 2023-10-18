#include "Array.hpp"
// #include <cstdlib>

// void leaks()
// {
//     system("leaks template");
// }

int main (void)
{
	// atexit(leaks);
	Array<int> iArray(5);
	std::cout << "size : " << iArray.size() << std ::endl;
	for (int i = 0; i < 5; i++)
		iArray[i] = i + 1;
	for (int i = 0; i < 5; i++)
		std::cout << iArray[i] << std::endl;

	try
	{
		// std::cout << iArray[-1] << std::endl;
		std::cout << iArray[6] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "=============================" << std::endl;

	Array<int> iArray2(iArray);
	for (int i = 0; i < 5; i++)
		std::cout << "iArray[" << i << "] = " << iArray[i] << " iArray2[" << i << "]= " << iArray2[i] << std::endl;
	std::cout << "iArray's address : " << iArray.getArray() << std::endl;
	std::cout << "iArray2's address : " << iArray2.getArray() << std::endl;
	
}
