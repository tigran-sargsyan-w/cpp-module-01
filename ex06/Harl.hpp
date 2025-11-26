#ifndef HARL_HPP
# define HARL_HPP

# define RESET   "\033[0m"
# define GRAY    "\033[90m"
# define GREEN   "\033[38;5;157m"
# define YELLOW  "\033[33m"
# define RED     "\033[1;31m"

# include <string>

class Harl
{
  public:
	Harl();
	Harl(const Harl &other);
	Harl &operator=(const Harl &other);
	~Harl();

	void complain(const std::string &level);

  private:
	void debug();
	void info();
	void warning();
	void error();
};

#endif
