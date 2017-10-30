#include <iostream>

int main()
{
    const int SIZE = 80;
    char buffer[ SIZE ];

    std::cout << "Enter a sentence:\n";
    std::cin.getline( buffer, SIZE );

    std::cout << "\nThe sentence entered is:" << std::endl
        << buffer << std::endl;

    return 0;
}
