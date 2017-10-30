#include <iostream>

int main()
{
    const int SIZE = 80;
    char buffer[ SIZE ];

    std::cout << "Enter a sentence: " << std::endl;
    std::cin.read( buffer, 10 );

    std::cout << "Sentence entered was: " << std::endl;
    std::cout.write( buffer, std::cin.gcount() );
    std::cout << std::endl;

    return 0;
}
