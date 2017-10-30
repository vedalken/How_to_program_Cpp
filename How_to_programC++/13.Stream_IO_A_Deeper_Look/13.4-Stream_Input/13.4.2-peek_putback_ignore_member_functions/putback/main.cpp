#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string fullName;

    std::cout << "Enter your full name: ";
    std::cin >> std::ws;
    char c = std::cin.get();

    if ( ! std::isalpha(c) )
    {
        std::cout << "You did not enter alpha numeric name" << std::endl;
        return 1;
    }

    std::cin.putback(c);
    std::getline( std::cin, fullName );

    std::cout << "Your full name is " << fullName << std::endl;

    return 0;
}
