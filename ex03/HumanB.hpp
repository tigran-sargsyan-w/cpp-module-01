#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
  private:
	std::string name;
    // Pointer to a Weapon object
    // Can be nullptr (no weapon)
	Weapon *weapon;

  public:
	HumanB();
	HumanB(const std::string &name);
	HumanB(const HumanB &other);
	HumanB &operator=(const HumanB &other);
	~HumanB();

	void setWeapon(Weapon &weapon);
	void attack() const;
};

#endif
