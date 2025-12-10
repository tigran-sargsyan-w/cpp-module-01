#include "HumanA.hpp"
#include <iostream>

/**
 * @brief Constructs a HumanA object with a name and a weapon.
 * @param name The name of the HumanA.
 * @param weapon A reference to the weapon.
 */
HumanA::HumanA(const std::string &name, Weapon &weapon)
	: name(name),
		weapon(weapon) {}

/**
 * @brief Constructs a HumanA by copying another HumanA.
 * @param other The other HumanA to copy.
 */
HumanA::HumanA(const HumanA &other)
	: name(other.name),
		weapon(other.weapon) {}

/**
 * @brief Assigns another HumanA to this one.
 * @param other The other HumanA to assign from.
 * @return A reference to this HumanA.
 */
HumanA &HumanA::operator=(const HumanA &other)
{
	if (this != &other)
	{
		name = other.name;
        // IMPORTANT:
        // weapon is a reference; it cannot be "rebound" in the assignment operator.
        // That means a HumanA always refers to the same Weapon after construction.
	}
	return (*this);
}

/**
 * @brief Destroys the HumanA object.
 */
HumanA::~HumanA() {}

/**
 * @brief Makes the HumanA attack with their weapon.
 */
void HumanA::attack() const
{
	std::cout << name
				<< " attacks with their "
				<< weapon.getType()
				<< std::endl;
}
