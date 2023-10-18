#include "Conversion.hpp"
// #include <cstdlib>

// void leaks()
// {
//     system("leaks convert");
// }

int main (int argc, char** argv)
{
	// atexit(leaks);
	if (argc != 2)
	{
		std::cerr << "wrong parameter" << std::endl;
		return 1;
	}
	std::string str = argv[1];

	Conversion convert(str);
	convert.checkLiterals();
}