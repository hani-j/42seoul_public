#include "Intern.hpp"

Intern::Intern() 
{}
Intern::~Intern() 
{}
Intern::Intern(const Intern& obj) 
{ *this = obj;}
Intern& Intern::operator=(const Intern& obj) 
{   
    if (this != &obj)
        return (*this);
    return (*this); 
}

Form* Intern::getPresidentForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}
Form* Intern::getRobotomyForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}
Form* Intern::getShrubberyForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

Form* Intern::makeForm(std::string formName, std::string target)
{
    std::string name[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
    Form* (Intern::*ptr[3])(std::string) = {&Intern::getShrubberyForm, &Intern::getRobotomyForm, &Intern::getPresidentForm};
    try
    {
        for (int i = 0; i < 3; i++)
        {
            if (name[i] == formName)
            {
                std::cout << "Intern creates " << formName << "Form" << std::endl;
                return (this->*ptr[i])(target);
            }
        }
        throw Intern::NoNameException();
    }
    catch(const std::exception& e)
    {
		std::cerr << "Intern can't create Form because " << formName << " ";
        std::cerr << e.what() << '\n';
    }
    return (NULL);
}

const char* Intern::NoNameException::what() const throw()
{
	return ("doesn't exist");
}