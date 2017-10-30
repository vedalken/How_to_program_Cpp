#include "Complex.h"

int main()
{
    Complex cmplx;
    std::cout << "Enter complex number: ";
    std::cin >> cmplx;

    if ( ! std::cin.good() )
    {
        std::cout << "Detected input error.";
        if ( (std::cin.rdstate() & std::cin.failbit) != 0 )
            std::cout << " Format error." << std::endl;

        return 1;
    }

    std::cout << cmplx << std::endl;

    return 0;
}
