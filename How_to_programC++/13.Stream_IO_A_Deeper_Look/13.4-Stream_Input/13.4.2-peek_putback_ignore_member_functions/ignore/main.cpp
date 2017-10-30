#include <iostream>
#include <string>

int main()
{
    std::string str;

    std::cout << "Enter a non-whitespace string: ";
    std::cin >> std::ws;
    std::cin.ignore(); // skip first character
    std::getline( std::cin, str );

    std::cout << "You enter: " << str
        << "\nbut with ignored first character" << std::endl;
    return 0;
}
