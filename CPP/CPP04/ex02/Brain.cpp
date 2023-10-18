#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "Brain's Default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "word";
}
Brain::~Brain() 
{
	std::cout << "Brain's Destructor called" << std::endl;
}
Brain::Brain(const Brain& b) 
{
	std::cout << "Brain's Copy constructor called" << std::endl;
    *this = b;
}
Brain& Brain::operator=(const Brain& b) 
{
	std::cout << "Brain's Copy assignment operator called" << std::endl;
	if (this != &b)
    {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = b._ideas[i];
    }
    return (*this);
}
