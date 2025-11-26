#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>

class Replacer {
private:
    std::string fileName;
    std::string search;
    std::string replacement;

    bool readFile(std::string &outContent) const;
    bool writeFile(const std::string &content) const;
    static std::string replaceAll(const std::string &text,
                                  const std::string &search,
                                  const std::string &replacement);

public:
    Replacer(const std::string &fileName,
             const std::string &search,
             const std::string &replacement);
    Replacer(const Replacer &other);
    Replacer &operator=(const Replacer &rhs);
    ~Replacer();

    bool process() const;
};

#endif
