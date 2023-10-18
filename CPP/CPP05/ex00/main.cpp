#include "Bureaucrat.hpp"
// #include <cstdlib>

// void leaks()
// {
//     system("leaks office");
// }

int main(void)
{
	// atexit(leaks);
	Bureaucrat bureaucrat("james", 150);
	std::cout << bureaucrat << std::endl;

	bureaucrat.decrementGrade();
	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl;

	std::cout << "======================================" << std::endl;

	try
	{
		Bureaucrat bureaucrat2("false", 151);
		std::cout << bureaucrat2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat bureaucrat2("false", 0);
		std::cout << bureaucrat2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "======================================" << std::endl;
	
	Bureaucrat bureaucrat2(bureaucrat);
	std::cout << bureaucrat2 << std::endl;

	Bureaucrat bureaucrat3("copy", 150);
	bureaucrat3 = bureaucrat;
	std::cout << bureaucrat3 << std::endl;
}
