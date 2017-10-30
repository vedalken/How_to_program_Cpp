#include <iostream>
#include <iomanip>

int main()
{
    int x = 10000;

    std::cout << x << " printed as int right and left justified\n"
        << "using as hex with internal justification.\n"
        << "Using the default pad character (space):\n";

    std::cout << std::showbase << std::setw( 10 ) << x << std::endl;

    std::cout << std::left << std::setw( 10 ) << x << std::endl;
    std::cout << std::internal << std::setw( 10 ) << std::hex << x << std::endl;

    std::cout << "\nUsing various padding characters:\n";

    std::cout << std::right;
    std::cout.fill('*');
    std::cout << std::setw( 10 ) << std::dec << x << std::endl;

    std::cout << std::left << std::setw( 10 ) << std::setfill('%') << x << std::endl;

    std::cout << std::internal << std::setw( 10 ) << std::setfill('^')
        << std::hex << x << std::endl;

    return 0;
}
