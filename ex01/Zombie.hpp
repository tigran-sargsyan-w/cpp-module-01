#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
  public:
	Zombie();
	Zombie(const Zombie &other);
	Zombie &operator=(const Zombie &other);
	~Zombie();
	
    explicit Zombie(const std::string &name);

	void announce() const;
	void setName(const std::string &newName);

  private:
	std::string name;
};

Zombie	*zombieHorde(int count, const std::string &name);

#endif
