#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include "Complex.h"

int main(int argc, char* argv[])
{
    if (argc < 3) {
        std::cerr << "Usage:\n"
             << argv[0] << " <real_arg> <imag_arg>" << std::endl;
        
        return EXIT_FAILURE;
    }
    
    double real;
    double imag;
    
    real = std::strtod(argv[1], nullptr);
    if (errno != EXIT_SUCCESS) {
        std::cerr << "strtod error: " << std::strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }
    
    imag = std::strtod(argv[2], nullptr);
    if (errno != EXIT_SUCCESS) {
        std::cerr << "strtod error: " << std::strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    // Initialize class with anonymous variables
    Complex c(real, imag);

    c.Print();

    std::cout << "\nAdd (1.32, -5.43)" << std::endl;
    c.Add(1.32, -5.43);
    
    c.Print();

    std::cout << "\nSubstract (1, 1)" << std::endl;
    c.Substract(1, 1);

    c.Print();
    std::cout << '\n';

    return EXIT_SUCCESS;
}
