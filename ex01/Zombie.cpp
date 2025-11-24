#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
	: name("noname") {}

Zombie::Zombie(const std::string &name)
	: name(name) {}

Zombie::Zombie(const Zombie &other)
	: name(other.name) {}

Zombie &Zombie::operator=(const Zombie &other)
{
	if (this != &other)
	{
		name = other.name;
	}
	return (*this);
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " destroyed" << std::endl;
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &newName)
{
	name = newName;
}
