#include <iostream>
#include <stdexcept>
#include "Array.h"

int main()
{
    Array integers1( 7 ); // seven-element Array
    Array integers2; // ten-element Array

    // print integers1 size and contents
    std::cout << "Size of Array integers1 is " << integers1.getSize()
        << "\nArray after initialization:\n" << integers1;

    // print integers2 size and contents
    std::cout << "Size of Array integers2 is " << integers2.getSize()
        << "\nArray after initialization:\n" << integers2;

    // input and print integers1 and integers2
    std::cin >> integers1 >> integers2;

    std::cout << "After input, the Arrays contain:\n"
        << "integers1:\n" << integers1
        << "integers2:\n" << integers2;

    // use overloaded inequality (i.e. !=) operator
    if ( integers1 != integers2 )
        std::cout << "integers1 and integers2 are not equal" << std::endl;

    // create Array integers3 using integers1 as an initializer
    // overloaded copy constructor
    Array integers3( integers1 );

    // print integers3 size and contents
    std::cout << "Size of Array integers3 is " << integers3.getSize()
        << "\nArray after initialization:\n" << integers3;

    // overloaded assignment operator
    std::cout << "\nAssigning integers2 to integers1:\n";
    integers1 = integers2;

    std::cout << "integers1:\n" << integers1
        << "intgers2:\n" << integers2;

    // use overloaded equality (i.e. ==) operator
    std::cout << "Evaluating: integers1 == integers2" << std::endl;

    if ( integers1 == integers2 )
        std::cout << "integers1 and integers2 are equal" << std::endl;

    // use overloaded subscript operator to create rvalue
    std::cout << "\nintegers1[5] is " << integers2[ 5 ];

    // use overloaded subscript operator to create lvalue
    integers1[ 5 ] = 1000;
    std::cout << "\nintegers1:\n" << integers1;

    try
    {
        std::cout << "\nAttempt to assign -9999 to integers1[100]" << std::endl;
        integers1[ 100 ] = -9999; // ERROR: subscript out of range
    }
    catch ( std::out_of_range& oor )
    {
        std::cout << "An exception occured: " << oor.what() << std::endl;
    }

    return 0;
}
