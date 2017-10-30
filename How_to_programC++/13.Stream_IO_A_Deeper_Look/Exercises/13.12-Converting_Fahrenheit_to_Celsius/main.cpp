#include <iostream>
#include <iomanip>

inline double Fahrenheit2Celsius( double fahrenheit )
{
    double celsius = 5.0 / 9.0 * ( fahrenheit - 32.0 );
    return celsius;
}

int main()
{
    const int minF = 0;
    const int maxF = 212;

    std::cout << std::setw( 10 ) << "F" << std::setw( 10 ) << "C" << std::endl
        << std::setw( 10 ) << "-------" << std::setw( 10 ) << "-------" << std::endl;

    std::cout << std::fixed << std::setprecision( 3 ) << std::showpos;

    for (int fahrenheit = minF; fahrenheit < maxF; ++fahrenheit)
    {
        std::cout << std::setw( 10 ) << fahrenheit << std::setw( 10 ) 
            << Fahrenheit2Celsius( fahrenheit ) << std::endl;
    }

    return 0;
}
