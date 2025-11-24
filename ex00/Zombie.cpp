#include "Zombie.hpp"
#include <iostream>

// Default constructor
Zombie::Zombie()
	: name("noname") {}

// Constructor with name
Zombie::Zombie(const std::string &name)
	: name(name) {}

// Copy constructor
Zombie::Zombie(const Zombie &other)
	: name(other.name) {}

// Copy assignment operator
Zombie &Zombie::operator=(const Zombie &other)
{
	if (this != &other)
	{
		name = other.name;
	}
	return (*this);
}

// Destructor
Zombie::~Zombie()
{
	std::cout << name << ": is destroyed" << std::endl;
}

// Announce method
void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
