#include "Zombie.hpp"

/**
 * @brief Creates a horde of zombies.
 * @param count The number of zombies in the horde.
 * @param name The name for each zombie in the horde.
 * @return A pointer to the first zombie in the horde, or 0 if count is non-positive.
 */
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
