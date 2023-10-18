#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string _type;
    public:
    Animal();
    Animal(const Animal& a);
    virtual ~Animal();
    Animal& operator=(const Animal& a);

    std::string getType() const;
    virtual void makeSound() const;
};

#endif

