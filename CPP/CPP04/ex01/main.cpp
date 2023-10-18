#include "Cat.hpp"
#include "Dog.hpp"
// #include <cstdlib>

// void leaks()
// {
//     system("leaks animal");
// }

int main()
{
    // atexit(leaks);
    Animal* animal[10];


    for (int i = 0; i < 5; i++)
    {
        animal[i] = new Dog();
    }

    std::cout << "================================================" << std::endl;
    
    for (int i = 5; i < 10; i++)
    {
        animal[i] = new Cat();
    }

    std::cout << "================================================" << std::endl;
    
    for (int i = 0; i < 10; ++i) 
    {
		delete animal[i];
	}

    std::cout << "================================================" << std::endl;

    Cat cat1;
    Cat cat2(cat1);
    Cat* cat3 = new Cat();
    *cat3 = cat1;

    std::cout << "cat 1 address : " << &cat1 << std::endl;
    std::cout << "cat 2 address : " << &cat2 << std::endl;
    std::cout << "cat 3 address : " << &cat3 << std::endl;
    std::cout << "cat 1 value's address : " << reinterpret_cast<void *>(cat1.getBrain()) << std::endl;
    std::cout << "cat 2 value's address : " << reinterpret_cast<void *>(cat2.getBrain()) << std::endl;
    std::cout << "cat 3 value's address : " << reinterpret_cast<void *>(cat3->getBrain()) << std::endl;
   
    delete cat3;



    std::cout << "================================================" << std::endl;
    Dog Dog1;
    Dog Dog2(Dog1);
    Dog* Dog3 = new Dog();
    *Dog3 = Dog1;

    std::cout << "Dog 1 address : " << &Dog1 << std::endl;
    std::cout << "Dog 2 address : " << &Dog2 << std::endl;
    std::cout << "Dog 3 address : " << &Dog3 << std::endl;
    std::cout << "Dog 1 value's address : " << reinterpret_cast<void *>(Dog1.getBrain()) << std::endl;
    std::cout << "Dog 2 value's address : " << reinterpret_cast<void *>(Dog2.getBrain()) << std::endl;
    std::cout << "Dog 3 value's address : " << reinterpret_cast<void *>(Dog3->getBrain()) << std::endl;
   
    delete Dog3;
    return 0;
}
