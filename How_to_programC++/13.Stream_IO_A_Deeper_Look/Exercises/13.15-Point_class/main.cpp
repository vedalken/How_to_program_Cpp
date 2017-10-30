#include "Point.h"

int main()
{
    std::cin.tie( &std::cout );

    Point point;
    std::cout << "Please enter 2D point (e.g. 0.0 1.0): ";
    std::cin >> point;

    if ( ! std::cin.good() )
    {
        std::cout << "Detected input error.";
        if ( (std::cin.rdstate() & std::cin.failbit) != 0 )
            std::cout << " Detected input format failbit error." << std::endl;

        return 1;
    }

    std::cout << "You entered point " << point << std::endl;

    return 0;
}
