#include <iostream>
#include <cmath>    // sqrt
#include <iomanip>  // setprecision

int main()
{
    double root2 = std::sqrt(2.0);

    std::cout << "sqrt(2) with precision 0-9." << std::endl
        << "Precision with ios_base member function: precision" << std::endl;

    // fixed-point notation
    std::cout << std::fixed;

    int places; // precision 0-9
    for ( places = 0; places <= 9; ++places )
    {
        std::cout.precision(places);
        std::cout << root2 << std::endl;
    }

    std::cout << "\nPrecision set by stream manipulator "
        << "setprecision: " << std::endl;

    for ( places = 0; places <= 9; ++places )
        std::cout << std::setprecision( places ) << root2 << std::endl;

    return 0;
}
