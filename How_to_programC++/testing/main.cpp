#include <iostream>
#include "storage8.h"

int main()
{
    // Define a Storage8 for integers
    Storage8int intStorage;
 
    for (int count=0; count<8; ++count)
        intStorage.set(count, count);
 
    for (int count=0; count<8; ++count)
        std::cout << intStorage.get(count) << '\n';
 
    // Define a Storage8 for bool
    Storage8<bool> boolStorage;
    for (int count=0; count<8; ++count)
        boolStorage.set(count, count & 3);

    for (int count=0; count<8; ++count)
        std::cout << (boolStorage.get(count) ? "true" : "false") << '\n';
 
    return 0;
}
