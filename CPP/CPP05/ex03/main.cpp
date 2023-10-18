#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
// #include <cstdlib>

// void leaks()
// {
//     system("leaks office");
// }

int main(void)
{
	// atexit(leaks);
	Intern intern;
	Form* shr;
	Form* shr2;
	Form* rob;
	Form* pre;

	shr = intern.makeForm("ShrubberyCreation", "home");
	std::cout << *shr << std::endl;

	shr2 = intern.makeForm("ShruryCreation", "home");
	(void)shr2;

	rob = intern.makeForm("RobotomyRequest", "pinokio");
	std::cout << *rob << std::endl;

	pre = intern.makeForm("PresidentialPardon", "target");
	std::cout << *pre << std::endl;

	std::cout << "======================================" << std::endl;

	Bureaucrat bureaucrat("james", 5);
	std::cout << bureaucrat << std::endl;

	bureaucrat.signForm(*rob);
	bureaucrat.executeForm(*rob);

	delete shr;
	delete rob;
	delete pre;
}
