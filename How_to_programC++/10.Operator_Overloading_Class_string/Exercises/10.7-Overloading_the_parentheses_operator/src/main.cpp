#include <iostream>
#include "DoubleSubscriptedArray.h"

int main()
{
    DoubleSubscriptedArray doubleArray(3, 4);
    
    std::cout << "doubleArray size: " << doubleArray.getSize() << std::endl;
    
    std::cout << "Enter " << doubleArray.getSize() << " integers:\n";
    std::cin >> doubleArray;
    
    std::cout << "After input, the double array contain:\n" << doubleArray;
    
    DoubleSubscriptedArray doubleArray1(1, 3);
    doubleArray1.reset();
    
    std::cout << "\ndoubleArray1 size: " << doubleArray1.getSize() << std::endl;
    std::cout << "Contents:\n" << doubleArray1;

    if ( doubleArray != doubleArray1 )
        std::cout << "\nThe double vectors differ\n";

    std::cout << "\nAssignment doubleArray1 = doubleArray\n";
    doubleArray1 = doubleArray;
    std::cout << "doubleArray:\n" << doubleArray;
    std::cout << "doubleArray1:\n" << doubleArray1;

    if ( doubleArray == doubleArray1 )
        std::cout << "\nThe double vectors are equal\n";

    std::cout << "\nSet doubleArray(1,1) = -1000\n";
    doubleArray(1, 1) = { -1000 };

    std::cout << "\nContents doubleArray:\n" << doubleArray;

    return 0;
}
