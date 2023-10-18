#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequest", 72, 45)
{
}
RobotomyRequestForm::~RobotomyRequestForm() 
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : Form(obj.getName(), obj.getSignGrade(), obj.getExecGrade())
{
    this->_target = obj._target;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) 
{
    if (this != &obj)
        this->_target = obj._target;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequest", 72, 45)
{
    this->_target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    checkExec(executor);
    srand((unsigned int)time(NULL));
    std::cout << "drrrrrrrr...  drrrrrrrrr" << std::endl;
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized successfully." << std::endl;
    else
        std::cout << this->_target << " robotomy failed." << std::endl;
}
