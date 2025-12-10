#include "Harl.hpp"

/**
 * @brief Main function to test the Harl class.
 * @return 0 on success.
 */
int main() 
{
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    harl.complain("RANDOM_LEVEL");

    return 0;
}
