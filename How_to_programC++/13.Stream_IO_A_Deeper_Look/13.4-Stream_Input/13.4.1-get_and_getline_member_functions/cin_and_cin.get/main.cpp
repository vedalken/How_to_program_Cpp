#include <iostream>

int main()
{
    const int SIZE = 80;
    char buffer1[ SIZE ];
    char buffer2[ SIZE ];

    // reads characters until a white-space character is encountered
    std::cout << "Enter a sentence:\n";
    std::cin >> buffer1;

    std::cout << "\nThe string read with cin was:\n"
        << buffer1 << std::endl;

    std::cin.get( buffer2, SIZE );

    std::cout << "The string read with cin.get was:\n"
        << buffer2 << std::endl;

    // discard delimiting character
    std::cin.ignore();

    return 0;
}
