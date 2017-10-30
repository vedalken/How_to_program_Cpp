#include <iostream>
#include "HugeInt.h"

int main()
{
    HugeInt n1, n2;

    std::cin >> n1 >> n2;
    
    HugeInt n6;
    n6 = n1 - n2;

    std::cout << n1 << " -\n" << n2 << "\n= " << n6 << std::endl;
    
    return 0;
}
