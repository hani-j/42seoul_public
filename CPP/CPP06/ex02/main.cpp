#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
// #include <cstdlib>

// void leaks()
// {
//     system("leaks convert");
// }

Base* generate(void)
{
	Base *base;

	srand(time(NULL));
	int num = rand() % 3;
	switch (num)
	{
		case 0 : 
			base = new A;
			break;
		case 1 :
			base = new B;
			break;
		default:
			base = new C;
			break;
	}
	return (base);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int main (void)
{
    // atexit(leaks);
	Base* base;

	base = generate();
	identify(base);
	identify(*base);

	delete base;
}