#include "Zombie.hpp"

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
