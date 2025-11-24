#include "Zombie.hpp"

Zombie* zombieHorde(int count, const std::string& name)
{
    if (count <= 0) { return 0; }

    Zombie* horde = new Zombie[count];

    for (int i = 0; i < count; ++i)
    {
        horde[i].setName(name);
    }
    return horde;
}
