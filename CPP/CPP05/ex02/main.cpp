#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
// #include <cstdlib>

// void leaks()
// {
//     system("leaks office");
// }

int main(void)
{
	// atexit(leaks);
	Bureaucrat bureaucrat("james", 5);
	std::cout << bureaucrat << std::endl;

	ShrubberyCreationForm shr("home");
	std::cout << shr << std::endl;

	RobotomyRequestForm rob("pinokio");
	std::cout << rob << std::endl;

	PresidentialPardonForm pre("target");
	std::cout << pre << std::endl;

	std::cout << "======================================" << std::endl;

	bureaucrat.executeForm(pre);
	bureaucrat.signForm(pre);
	std::cout << pre << std::endl;

	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl;
	bureaucrat.executeForm(pre);
	
}
