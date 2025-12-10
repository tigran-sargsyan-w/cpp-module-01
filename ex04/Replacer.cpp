#include "Replacer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * @brief Constructs a Replacer object.
 * @param fileName The name of the file to process.
 * @param search The string to search for.
 * @param replacement The string to replace with.
 */
Replacer::Replacer(const std::string &fileName,
                   const std::string &search,
                   const std::string &replacement)
    : fileName(fileName),
      search(search),
      replacement(replacement) {}

/**
 * @brief Constructs a Replacer object by copying another Replacer.
 * @param other The other Replacer object to copy.
 */
Replacer::Replacer(const Replacer &other)
    : fileName(other.fileName),
      search(other.search),
      replacement(other.replacement) {}

/**
 * @brief Assigns another Replacer object to this one.
 * @param rhs The other Replacer object to assign from.
 * @return A reference to this Replacer object.
 */
Replacer &Replacer::operator=(const Replacer &rhs)
{
    if (this != &rhs)
    {
        fileName = rhs.fileName;
        search = rhs.search;
        replacement = rhs.replacement;
    }
    return *this;
}

/**
 * @brief Destroys the Replacer object.
 */
Replacer::~Replacer() {}

/**
 * @brief Reads the content of the input file.
 * @param outContent A reference to a string where the file content will be stored.
 * @return True on success, false on error.
 */
bool Replacer::readFile(std::string &outContent) const
{
    std::ifstream infile;

    infile.open(fileName.c_str());
    if (!infile)
    {
        std::cerr << "Error: cannot open input file: "
                  << fileName << std::endl;
        return false;
    }

    std::ostringstream buffer;
    buffer << infile.rdbuf();
    if (!infile.good() && !infile.eof())
    {
        std::cerr << "Error: failed while reading input file: "
                  << fileName << std::endl;
        return false;
    }
    outContent = buffer.str();
    return true;
}

/**
 * @brief Writes the given content to the output file.
 * @param content The content to write to the file.
 * @return True on success, false on error.
 */
bool Replacer::writeFile(const std::string &content) const
{
    std::ofstream outfile;
    std::string outName = fileName + ".replace";

    outfile.open(outName.c_str());
    if (!outfile)
    {
        std::cerr << "Error: cannot open output file: "
                  << outName << std::endl;
        return false;
    }

    outfile << content;
    if (!outfile.good())
    {
        std::cerr << "Error: failed while writing to output file: "
                  << outName << std::endl;
        return false;
    }

    return true;
}

/**
 * @brief Replaces all occurrences of a search string with a replacement string.
 * @param text The text to perform the replacement on.
 * @param search The string to search for.
 * @param replacement The string to replace with.
 * @return The modified string.
 */
std::string Replacer::replaceAll(const std::string &text,
                                 const std::string &search,
                                 const std::string &replacement)
{
    std::string result;
    std::size_t pos = 0;
    std::size_t found;

    while ((found = text.find(search, pos)) != std::string::npos)
    {
        // All characters from pos up to the found position
        result.append(text, pos, found - pos);
        // Insert replacement instead of search
        result.append(replacement);
        // Move position past the found fragment
        pos = found + search.length();
    }
    // Remainder of the string after the last match
    result.append(text, pos, std::string::npos);
    return result;
}

/**
 * @brief Processes the file, replacing all occurrences of the search string.
 * @return True on success, false on error.
 */
bool Replacer::process() const
{
    if (search.empty())
    {
        std::cerr << "Error: search string (s1) must not be empty"
                  << std::endl;
        return false;
    }

    std::string content;
    if (!readFile(content))
        return false;

    std::string replaced = replaceAll(content, search, replacement);

    if (!writeFile(replaced))
        return false;

    return true;
}
