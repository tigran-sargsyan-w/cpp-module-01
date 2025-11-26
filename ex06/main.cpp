#include "Harl.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0]
                  << " <DEBUG|INFO|WARNING|ERROR>" << std::endl;
        return 1;
    }

    std::string inputLevel = argv[1];
    const std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    int idx = -1;
    for (int i = 0; i < 4; ++i)
    {
        if (inputLevel == levels[i])
        {
            idx = i;
            break;
        }
    }

    Harl harl;

    switch (idx)
    {
        case 0:
            harl.complain("DEBUG");
            // fall through
        case 1:
            harl.complain("INFO");
            // fall through
        case 2:
            harl.complain("WARNING");
            // fall through
        case 3:
            harl.complain("ERROR");
            break;
        default:
            std::cout << RED << "[ UNKNOWN ] \t"
            << "Let's ignore minor whining."
            << RESET << std::endl;
    }
    return 0;
}
