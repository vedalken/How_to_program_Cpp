#include <iostream>
#include <iomanip>

int main()
{
    // print integer 40000 left justified in a 15-digit field
    std::cout << std::setw( 15 ) << std::left << 40000 << std::endl;

    // print 200 with and without a sign
    std::cout << 200 << '\t' << std::showpos << 200 << std::endl;

    // print decimal 100 in hexadecimal form preceded by 0x
    std::cout << std::showbase << std::hex << 100 << std::endl;

    // print 1.234 in a 9-digit field with preceding zeros
    std::cout << std::setw( 9 ) << std::setfill('0') << 1.234 << std::endl;
    std::cout.fill(' ');

    // read a string into character array variable state
    char stat[ 80 ];
    std::cout << "Enter some string: ";
    std::cin.read( stat, 10 );
    if (! std::cin.good())
    {
        std::cerr << "Reading input is not goodbit!" << std::endl;
        return 1;
    }

    std::cout << "Entered sentence was:" << std::endl;
    std::cout.write( stat, std::cin.gcount() );
    std::cout << std::endl;

    // read characters into array until the character 'p' is encountered
    // up to limit of 10 characters
    char charArray[ 10 ];
    std::cout << "Enter string (read string until character p is encounted):\n";
    std::cin.get( charArray, 10, 'p' );
    std::cout << charArray << std::endl;

    return 0;
}
