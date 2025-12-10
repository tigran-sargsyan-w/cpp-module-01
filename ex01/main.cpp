#include "Zombie.hpp"

/**
 * @brief Main function to test the zombieHorde function.
 * @return 0 on success, 1 on error.
 */
int main()
{
    int count = 5;

    Zombie* horde = zombieHorde(count, "TestZombie");
    if (!horde) { return 1; }

    for (int i = 0; i < count; ++i) 
    {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}
