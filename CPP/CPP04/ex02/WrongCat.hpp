#ifndef WRONGCAT_CPP
#define WRONGCAT_CPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    private:
    public:
        WrongCat();
        WrongCat(const WrongCat& c);
        ~WrongCat();
        WrongCat& operator=(const WrongCat& c);

        void makeSound() const;
};

#endif
