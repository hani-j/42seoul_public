#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}
Bureaucrat::~Bureaucrat()
{
}
Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade)
{
	if (obj._grade < 1)
		throw GradeTooHighException();
	if (obj._grade > 150)
		throw GradeTooLowException();
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) 
{
	if (this != &obj)
	{
		this->_grade = obj._grade;
	}
	return (*this);
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}
int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (this->_grade <= 1)
			throw GradeTooHighException();
		this->_grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
void Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade >= 150)
			throw GradeTooLowException();
		this->_grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
