#include <iostream>
#include <stdexcept>
#include "Array.h"

int main()
{
    Array<int> integers1( 7 ); // seven-element Array
    Array<double> integers2; // ten-element Array

    integers2[0] = 3.14159236;
    integers2.back() = -23123.432;

    // print integers1 size and contents
    std::cout << "Size of Array integers1 is " << integers1.getSize()
        << "\nArray after initialization:\n" << integers1;

    // print integers2 size and contents
    std::cout << "Size of Array integers2 is " << integers2.getSize()
        << "\nArray after initialization:\n" << integers2;

    return 0;
}
