#include "HumanB.hpp"
#include <iostream>

/**
 * @brief Default constructor for the HumanB class.
 */
HumanB::HumanB()
	: name("Unnamed"),
		weapon(0) {}

/**
 * @brief Constructs a HumanB object with a given name.
 * @param name The name of the HumanB.
 */
HumanB::HumanB(const std::string &name)
	: name(name),
		weapon(0) {}

/**
 * @brief Constructs a HumanB by copying another HumanB.
 * @param other The other HumanB to copy.
 */
HumanB::HumanB(const HumanB &other)
	: name(other.name),
		weapon(other.weapon) {}

/**
 * @brief Assigns another HumanB to this one.
 * @param other The other HumanB to assign from.
 * @return A reference to this HumanB.
 */
HumanB &HumanB::operator=(const HumanB &other)
{
	if (this != &other)
	{
		name = other.name;
		weapon = other.weapon;
	}
	return (*this);
}

/**
 * @brief Destroys the HumanB object.
 */
HumanB::~HumanB() {}

/**
 * @brief Sets the weapon for the HumanB.
 * @param weapon A reference to the weapon to set.
 */
void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

/**
 * @brief Makes the HumanB attack with their weapon.
 */
void HumanB::attack() const
{
	if (weapon)
	{
		std::cout << name
					<< " attacks with their "
					<< weapon->getType()
					<< std::endl;
	}
	else
	{
		std::cout << name
					<< " has no weapon to attack with"
					<< std::endl;
	}
}
