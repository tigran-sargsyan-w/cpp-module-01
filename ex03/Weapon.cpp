#include "Weapon.hpp"

Weapon::Weapon()
	: type("bare hands") {}

Weapon::Weapon(const std::string &type)
	: type(type) {}

Weapon::Weapon(const Weapon &other)
	: type(other.type) {}

Weapon &Weapon::operator=(const Weapon &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Weapon::~Weapon() {}

const std::string &Weapon::getType() const
{
	return (type);
}

void Weapon::setType(const std::string &newType)
{
	type = newType;
}
