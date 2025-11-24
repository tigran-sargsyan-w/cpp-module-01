#include <iostream>
#include <string>

int main()
{
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPtr = &brain;
    std::string& stringRef = brain;

    // Addresses
    std::cout << "Address of brain      : " << &brain << std::endl;
    std::cout << "Address in stringPtr  : " << stringPtr << std::endl;
    std::cout << "Address of stringRef  : " << &stringRef << std::endl;

    std::cout << std::endl;

    // Values
    std::cout << "Value of brain        : " << brain << std::endl;
    std::cout << "Value via stringPtr   : " << *stringPtr << std::endl;
    std::cout << "Value via stringRef   : " << stringRef << std::endl;

    return 0;
}
