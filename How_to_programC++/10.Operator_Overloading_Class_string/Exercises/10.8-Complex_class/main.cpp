#include <iostream>
#include "Complex.h"

int main()
{
    Complex x;
    Complex y( 4.3, 8.2 );
    Complex z( 3.3, 1.1 );

    std::cout << "x: " << x
        << "\ny: " << y
        << "\nz: " << z << std::endl;

    x = y + z;
    std::cout << "\n\n x = y + z: " << x << std::endl;

    x = y - z;
    std::cout << "\n\n x = y - z: " << x << std::endl;
   
    x += y ;
    std::cout << "\n\n x += y: " << x << std::endl;

    x = y * z;
    std::cout << "\n\n x = y * z: " << x << std::endl;

    return 0;
}
