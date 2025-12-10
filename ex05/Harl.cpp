#include "Harl.hpp"
#include <iostream>

/**
 * @brief Default constructor for the Harl class.
 */
Harl::Harl() {}

/**
 * @brief Copy constructor for the Harl class.
 * @param other The other Harl instance to copy from (unused).
 */
Harl::Harl(const Harl& other) { (void)other; }

/**
 * @brief Assignment operator for the Harl class.
 * @param other The other Harl instance to assign from (unused).
 * @return A reference to the current Harl instance.
 */
Harl& Harl::operator=(const Harl& other) 
{
    (void)other;
    return *this;
}

/**
 * @brief Destructor for the Harl class.
 */
Harl::~Harl() {}

/**
 * @brief Prints a debug message.
 */
void Harl::debug() 
{
    std::cout
        << GRAY << "[ DEBUG ] \t"
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
        << RESET << std::endl;
}

/**
 * @brief Prints an info message.
 */
void Harl::info()
{
    std::cout
        << GREEN << "[ INFO ] \t"
        << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
        << RESET << std::endl;
}

/**
 * @brief Prints a warning message.
 */
void Harl::warning()
{
    std::cout
        << YELLOW << "[ WARNING ] \t"
        << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
        << RESET << std::endl;
}

/**
 * @brief Prints an error message.
 */
void Harl::error()
{
    std::cout
        << RED << "[ ERROR ] \t"
        << "This is unacceptable! I want to speak to the manager now."
        << RESET << std::endl;
}

/**
 * @brief Calls a complaint method based on the level.
 * @param level The complaint level (DEBUG, INFO, WARNING, ERROR).
 */
void Harl::complain(const std::string& level)
{
    typedef void (Harl::*HarlMethod)();

    const std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    HarlMethod methods[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; ++i) 
    {
        if (levels[i] == level) 
        {
            (this->*methods[i])();
            return;
        }
    }

    std::cout 
        << "[Unknown] \t" << level << std::endl;
}
