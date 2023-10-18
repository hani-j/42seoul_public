#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
		Form();
	public:
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& obj);
		virtual ~Form();
		Form& operator=(const Form& obj);

		std::string getName() const;
		bool getIsSigned() const;
        int getSignGrade() const;
        int getExecGrade() const;

		void beSigned(Bureaucrat b);
		virtual void execute(Bureaucrat const & executor) const = 0;
		void checkExec(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class NoSignException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
