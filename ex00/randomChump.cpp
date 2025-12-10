#include "Zombie.hpp"

/**
 * @brief Creates a zombie on the stack and makes it announce itself.
 * @param name The name of the zombie.
 */
void	randomChump(const std::string &name)
{
	Zombie zombie(name);
	zombie.announce();
}
