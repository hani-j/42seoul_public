#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardon", 25, 5)
{
}
PresidentialPardonForm::~PresidentialPardonForm() 
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : Form(obj.getName(), obj.getSignGrade(), obj.getExecGrade())
{
    this->_target = obj._target;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) 
{
    if (this != &obj)
        this->_target = obj._target;
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardon", 25, 5)
{
    this->_target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    checkExec(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
