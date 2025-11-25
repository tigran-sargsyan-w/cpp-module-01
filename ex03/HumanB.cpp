#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB()
	: name("Unnamed"),
		weapon(0) {}

HumanB::HumanB(const std::string &name)
	: name(name),
		weapon(0) {}

HumanB::HumanB(const HumanB &other)
	: name(other.name),
		weapon(other.weapon) {}

HumanB &HumanB::operator=(const HumanB &other)
{
	if (this != &other)
	{
		name = other.name;
		weapon = other.weapon;
	}
	return (*this);
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

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
