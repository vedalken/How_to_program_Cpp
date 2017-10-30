#include <iostream>

int main()
{
    char sentence[10]; // buffer

    std::cout << "Enter a sentence:" << std::endl;
    std::cin.width( 5 );

    int offsetWidth = 4;
    while ( std::cin >> sentence )
    {
        std::cout.width( offsetWidth++ );
        std::cout << sentence << std::endl;
        std::cin.width( 5 );
    }

    return 0;
}
