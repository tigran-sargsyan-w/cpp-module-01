#include "Zombie.hpp"
#include <iostream>

/**
 * @brief Default constructor for the Zombie class.
 */
Zombie::Zombie()
	: name("noname") {}

/**
 * @brief Constructs a Zombie object with a given name.
 * @param name The name of the zombie.
 */
Zombie::Zombie(const std::string &name)
	: name(name) {}

/**
 * @brief Constructs a Zombie by copying another Zombie.
 * @param other The other Zombie to copy.
 */
Zombie::Zombie(const Zombie &other)
	: name(other.name) {}

/**
 * @brief Assigns another Zombie to this one.
 * @param other The other Zombie to assign from.
 * @return A reference to this Zombie.
 */
Zombie &Zombie::operator=(const Zombie &other)
{
	if (this != &other)
	{
		name = other.name;
	}
	return (*this);
}

/**
 * @brief Destroys the Zombie object.
 */
Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " destroyed" << std::endl;
}

/**
 * @brief Makes the zombie announce itself.
 */
void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/**
 * @brief Sets the name of the zombie.
 * @param newName The new name for the zombie.
 */
void Zombie::setName(const std::string &newName)
{
	name = newName;
}
