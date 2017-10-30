#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cout << "Enter a string (with \" or \'): ";
    std::getline( std::cin, str );

    std::cout << "Entered string:\n" << str << std::endl;
    return 0;
}
