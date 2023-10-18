#include "Zombie.hpp"

int main()
{
    Zombie stack_zombie = Zombie("Stack_Zombie");
    stack_zombie.announce();

    Zombie *heap_zombie = new Zombie("Heap_Zombie");
    heap_zombie->announce();
    
    Zombie *new_zombie = newZombie("New_Zombie");
    new_zombie->announce();

    randomChump("randomChump");

    delete heap_zombie;
    delete new_zombie;
}
