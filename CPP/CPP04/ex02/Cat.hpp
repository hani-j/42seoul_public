#ifndef CAT_CPP
#define CAT_CPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat& c);
        ~Cat();
        Cat& operator=(const Cat& c);

        virtual void makeSound() const;
        Brain* getBrain() const;
};

#endif
