#include "Bureaucrat.hpp"
// #include <cstdlib>

// void leaks()
// {
//     system("leaks office");
// }

int main(void)
{
	// atexit(leaks);
	try
	{
		Form form("false", 151, 150);
		std::cout << form<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form form("false", 0, 150);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "======================================" << std::endl;

	Bureaucrat bureaucrat("james", 150);
	Form form("cleening", 149, 140);
	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;

	std::cout << "======================================" << std::endl;

	bureaucrat.signForm(form);
	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;

	std::cout << "======================================" << std::endl;
	
	bureaucrat.incrementGrade();
	bureaucrat.signForm(form);
	std::cout << bureaucrat << std::endl;
	std::cout << form << std::endl;
}
