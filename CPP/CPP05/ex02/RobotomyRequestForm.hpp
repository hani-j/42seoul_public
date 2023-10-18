#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form 
{
    private:
        std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& obj);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

        void execute(Bureaucrat const & executor) const;
};

#endif

