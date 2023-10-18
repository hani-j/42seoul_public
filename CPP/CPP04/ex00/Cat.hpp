#ifndef CAT_CPP
#define CAT_CPP

#include "Animal.hpp"

class Cat : public Animal{
    private:
    public:
        Cat();
        Cat(const Cat& c);
        ~Cat();
        Cat& operator=(const Cat& c);

        virtual void makeSound() const;
};

#endif
