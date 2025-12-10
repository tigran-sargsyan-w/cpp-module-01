#include "Zombie.hpp"

/**
 * @brief Main function to test the Zombie class.
 * @return 0 on success.
 */
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
