#include "Weapon.hpp"

/**
 * @brief Default constructor for the Weapon class.
 */
Weapon::Weapon()
	: type("bare hands") {}

/**
 * @brief Constructs a Weapon object with a given type.
 * @param type The type of the weapon.
 */
Weapon::Weapon(const std::string &type)
	: type(type) {}

/**
 * @brief Constructs a Weapon by copying another Weapon.
 * @param other The other Weapon to copy.
 */
Weapon::Weapon(const Weapon &other)
	: type(other.type) {}

/**
 * @brief Assigns another Weapon to this one.
 * @param other The other Weapon to assign from.
 * @return A reference to this Weapon.
 */
Weapon &Weapon::operator=(const Weapon &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

/**
 * @brief Destroys the Weapon object.
 */
Weapon::~Weapon() {}

/**
 * @brief Gets the type of the weapon.
 * @return A constant reference to the weapon's type.
 */
const std::string &Weapon::getType() const
{
	return (type);
}

/**
 * @brief Sets the type of the weapon.
 * @param newType The new type for the weapon.
 */
void Weapon::setType(const std::string &newType)
{
	type = newType;
}
