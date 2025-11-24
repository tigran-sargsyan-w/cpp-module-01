#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
    Zombie();
    Zombie(const Zombie& other);
    Zombie& operator=(const Zombie& other);
    ~Zombie();

    explicit Zombie(const std::string& name);

    void announce() const;
private:
    std::string name;
};

Zombie* newZombie(const std::string& name);
void    randomChump(const std::string& name);

#endif
