#include <iostream>
#include <string>
#include <climits>
#include <cmath>

int main(void)
{
	int a = 300;
	char c = static_cast<char>(a);
	std::cout << c << std::endl;

	float fZero = 0.0f;
	float fNan = 0 / fZero;
	float fInf = 1 / fZero;
	std::cout << fNan << std::endl;
	std::cout << fInf << std::endl;


	double dZero = 0.0;
	double dNan = 0 / dZero;
	double dInf = 1 / dZero;
	std::cout << dNan << std::endl;
	std::cout << dInf << std::endl;

	// double d = 1231233;
	
	// std::cout.precision(6);
	int ff = static_cast<int>(dInf);
	std::cout  << ff << std::endl;
	// << std::fixed

	std::string str = "+42";
	std :: cout << atoi(str.c_str()) << std::endl;
}
