#include "Zombie.hpp"

int main() 
{
    // Zombie on the heap
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    // Zombie on the stack
    randomChump("StackZombie");
    return 0;
}
