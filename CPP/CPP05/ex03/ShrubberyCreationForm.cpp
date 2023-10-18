#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreation", 145, 137)
{
}
ShrubberyCreationForm::~ShrubberyCreationForm() 
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : Form(obj.getName(), obj.getSignGrade(), obj.getExecGrade())
{
    this->_target = obj._target;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) 
{
    if (this != &obj)
        this->_target = obj._target;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreation", 145, 137)
{
    this->_target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::ofstream outfile;
    std::string outfileName;

    checkExec(executor);
    outfileName = this->_target;
    outfileName = outfileName.append("_shrubbery");
    outfile.open(outfileName.c_str());
    if (outfile.fail())
    {
        std::cerr << "Open Error" << std::endl;
        return ;
    }
    outfile
    << "       _-_" << std::endl
    << "    /~~   ~~\\" << std::endl
    << " /~~         ~~\\" << std::endl
    << "{               }" << std::endl
    << " \\  _-     -_  /" << std::endl
    << "   ~  \\\\ //  ~" << std::endl
    << "_- -   | | _- _" << std::endl
    << "  _ -  | |   -_" << std::endl
    << "      // \\\\" << std::endl;

    outfile.close();
}
