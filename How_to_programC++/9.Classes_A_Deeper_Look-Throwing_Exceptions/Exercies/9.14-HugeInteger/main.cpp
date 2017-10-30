#include <iostream>
#include "HugeInteger.h"

int main()
{
    HugeInteger hugeInteger1;
    HugeInteger hugeInteger2;
    
    hugeInteger2.input();
    hugeInteger1.input();
    
    //HugeInteger tmpHugeInteger = hugeInteger2;

    //// sum two numbers 
    //hugeInteger2.substract(hugeInteger1);

    //hugeInteger1.output(); std::cout << '\n';
    //std::cout << "The substraction: "; 
    //hugeInteger2.output(); 
    //std::cout << '\n';
    //
    //std::cout << "*** Test substraction ***" 
    //          << "\noriginal: "; 
    //tmpHugeInteger.output();
    hugeInteger2.add(hugeInteger1);
    std::cout << "\ntest:     "; 
    hugeInteger2.output();
    std::cout << '\n';

    return 0;
}
