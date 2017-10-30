#include <iostream>
#include "Date.h"

int main()
{
    Date d1( 3, 5, 2008 );
    Date d2;

    std::cout << "d1: " << d1 << "\nd2: " << d2;
    std::cout << "\n\nd1 += 7 is " << ( d1 += 7 );

    d2.setDate( 2, 28, 2008 );
    std::cout << "\n\nd2 is " << d2;
    std::cout << "\n++d2 is " << ++d2 << " (leap year allows 29th)";

    Date d3( 7, 13, 2010 );

    std::cout << "\n\nTesting the prefix increment operator:"
        << "\nd3 is " << d3 << std::endl;
    std::cout << "++d3 is " << ++d3 << std::endl;
    std::cout << "d3 is " << d3 << std::endl;

    std::cout << "\n\nTesting the postfix increment operator:"
        << "\nd3 is " << d3 << std::endl;
    std::cout << "d3++ is " << d3++ << std::endl;
    std::cout << "d3 is " << d3 << std::endl;

    return 0;
}
