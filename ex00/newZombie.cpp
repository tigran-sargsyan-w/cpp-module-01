#include "Zombie.hpp"

/**
 * @brief Creates a zombie on the heap.
 * @param name The name of the zombie.
 * @return A pointer to the newly created zombie.
 */
Zombie	*newZombie(const std::string &name)
{
	Zombie	*zombie;

	zombie = new Zombie(name);
	return (zombie);
}
