#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern 
{
    private:
    public:
        Intern();
        Intern(const Intern& obj);
        ~Intern();
        Intern& operator=(const Intern& obj);

        Form* getPresidentForm(std::string target);
        Form* getRobotomyForm(std::string target);
        Form* getShrubberyForm(std::string target);
        Form* makeForm(std::string formName, std::string target);
        class NoNameException : public std::exception
        {
            public :
                const char* what() const throw();
        };
};

#endif
