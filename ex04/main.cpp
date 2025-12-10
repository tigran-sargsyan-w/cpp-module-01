#include <iostream>
#include <string>
#include "Replacer.hpp"

/**
 * @brief Main function for the replacer program.
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments: filename, string to find, and string to replace.
 * @return 0 on success, 1 on error.
 */
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0]
                  << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string fileName = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    Replacer replacer(fileName, s1, s2);
    if (!replacer.process())
        return 1;

    return 0;
}
