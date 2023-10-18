#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string _type;
    public:
    Animal();
    Animal(const Animal& obj);
    virtual ~Animal();
    Animal& operator=(const Animal& obj);

    std::string getType() const;
    virtual void makeSound() const;
};

#endif

