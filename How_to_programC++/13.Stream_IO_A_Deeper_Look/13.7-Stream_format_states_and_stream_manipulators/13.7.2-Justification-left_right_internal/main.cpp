#include <iostream>
#include <iomanip>

int main()
{
    int x = 12345;

    std::cout << "Default is right justification\n"
        << std::setw( 10 ) << x;

    std::cout << "\n\nUse left justification\n"
        << std::left << std::setw( 10 ) << x;

    std::cout << "\n\nUse right justification\n"
        << std::right << std::setw( 10 ) << x
        << '\n' << std::endl;

    std::cout << "Display x with internal spacing and plus sign:\n";
    std::cout << std::internal << std::showpos << std::setw( 10 ) << x << std::endl;

    std::cout << "Reset showpos with noshowpos:\n"
        << std::internal << std::noshowpos << std::setw( 10 ) << x << std::endl;

    return 0;
}
