#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
// #include <cstdlib>

// void leaks()
// {
//     system("leaks animal");
// }

int main()
{
    // atexit(leaks);
    // const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    // meta->makeSound();

    std::cout << "================================================" << std::endl;

    const WrongAnimal* wani = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();
    std::cout << wani->getType() << " " << std::endl;
    std::cout << wc->getType() << " " << std::endl;
    wani->makeSound();
    wc->makeSound(); //will not output the cat sound!

    std::cout << "================================================" << std::endl;
    // delete meta;
    delete i;
    delete j;
    delete wani;
    delete wc;
    return 0;
}
