#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
}
Form::~Form() 
{
}
Form::Form(std::string name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}
Form::Form(const Form& obj) : _name(obj._name), _isSigned(obj._isSigned), _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
	if (obj._signGrade < 1 || obj._execGrade < 1)
		throw GradeTooHighException();
	if (obj._signGrade > 150 || obj._execGrade > 150)
		throw GradeTooLowException();
}
Form& Form::operator=(const Form& obj) 
{
	if (this != &obj)
	{
		this->_isSigned = obj._isSigned;
	}
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}
bool Form::getIsSigned() const
{
	return (this->_isSigned);
}
int Form::getSignGrade() const
{
	return (this->_signGrade);
}
int Form::getExecGrade() const
{
	return (this->_execGrade);
}

void Form::beSigned(Bureaucrat b)
{
	if (this->_signGrade < b.getGrade())
		throw GradeTooLowException();
	this->_isSigned = true;
}

void Form::checkExec(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw NoSignException();
    if (this->getExecGrade() < executor.getGrade())
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}
const char* Form::NoSignException::what() const throw()
{
	return ("No Sign");
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() 
	<< ", is signed : " << obj.getIsSigned() 
	<< ", sign grade : " << obj.getSignGrade() 
	<< ", execute grade : " << obj.getExecGrade() ;
	return os;
}
