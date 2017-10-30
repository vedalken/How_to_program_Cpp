#include <iostream>
#include <iomanip>

int main()
{
    const size_t roundDigits = 5;
    double value = 100.453627;
    int precision = std::cout.precision();

    std::cout << std::fixed;
    for ( size_t round = 0; round <= roundDigits; ++round )
        std::cout << std::setprecision( round ) << value << std::endl;

    std::cout << "\nDefault precision: ";
    std::cout << std::setprecision( precision ) << value << std::endl;

    return 0;
}
