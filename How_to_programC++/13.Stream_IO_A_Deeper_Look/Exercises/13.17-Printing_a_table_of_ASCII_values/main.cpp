#include <iostream>
#include <iomanip>

int main()
{
    std::cout << std::showbase
        << std::setw( 5 )  << "char"
        << std::setw( 10 ) << "dec"
        << std::setw( 10 ) << "oct"
        << std::setw( 10 ) << "hex"
        << std::endl;

    int value{};
    for ( char c = 33; c <= 126; ++c )
    {
        value = static_cast<int>( c );
        std::cout << std::setw( 5 ) << c
            << std::dec << std::setw( 10 ) << value
            << std::oct << std::setw( 10 ) << value
            << std::hex << std::setw( 10 ) << value << std::endl;
    }

    return 0;
}
