#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Rational.h"

int main(int argc, char* argv[])
{
    if (argc < 3) {
        std::cerr << "Usage:\n"
                  << argv[0] << " <numerator> <denominator>" << std::endl;
        return EXIT_FAILURE;
    }
    
    int nom, denom;

    nom = std::atoi(argv[1]);
    if (nom == 0) {
        std::cerr << "Nominator is not integer" << std::endl;
        return EXIT_FAILURE;
    }
    
    denom = std::atoi(argv[2]);
    if (denom == 0) {
        std::cerr << "Denominator is not integer or is zero or is out of range" << std::endl;
        return EXIT_FAILURE;
    }

    Rational rat(nom, denom);
    
    rat.PrintRationalFormat();
    rat.PrintRationalFormat();

    rat.Add(Rational{3, 4}).Substract(Rational{1, 5}).Divide(Rational{1, 2});
    
    rat.PrintRationalFormat();
    rat.PrintFloatFormat();

    return EXIT_SUCCESS;
}
