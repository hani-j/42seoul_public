#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    private:
    public:
        Dog();
        Dog(const Dog& d);
        ~Dog();
        Dog& operator=(const Dog& d);
        
        virtual void makeSound() const;
};

#endif
