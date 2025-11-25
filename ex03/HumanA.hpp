#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA
{
  private:
	std::string name;
    // Reference to a Weapon object
    // Always has a weapon (no nullptr)
	Weapon &weapon; 

  public:
	// no default constructor: must always have a weapon
	HumanA(const std::string &name, Weapon &weapon);
	HumanA(const HumanA &other);
	HumanA &operator=(const HumanA &other);
	~HumanA();

	void attack() const;
};

#endif
