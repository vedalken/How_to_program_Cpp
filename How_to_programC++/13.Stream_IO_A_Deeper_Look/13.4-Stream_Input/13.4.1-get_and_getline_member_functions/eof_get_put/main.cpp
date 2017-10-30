#include <iostream>

int main()
{
    int character;

    std::cout << "Before input, cin.eof() is " << std::cin.eof()
        << "\nEnter a sentence followed by end-of-file:\n";

    while ( (character = std::cin.get()) != EOF )
        std::cout.put(character);

    std::cout << "\nEOF in this system is: " << character;
    std::cout << "\nAfter input, cin.eof() is " << std::cin.eof() << std::endl;

    return 0;
}
