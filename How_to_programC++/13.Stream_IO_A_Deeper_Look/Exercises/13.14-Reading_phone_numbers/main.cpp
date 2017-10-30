#include "PhoneNumber.h"

int main()
{
    PhoneNumber phone;

    std::cout << "Enter a phone number in the form (XXX) XXX-XXXX: ";
    std::cin >> phone;

    if (! std::cin.good() )
    {
        std::cerr << "Error state detected in standard input.";

        if ( (std::cin.rdstate() & std::cin.failbit) != 0 )
            std::cerr << " Logical error on input operation";

        std::cerr << std::endl;
        return 1;
    }

    std::cout << phone;

    return 0;
}
