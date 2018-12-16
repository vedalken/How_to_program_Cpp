// Demonstrating class PhoneNumber's overloaded stream insertion and stream
// extraction operators
#include <iostream>
#include "PhoneNumber.h"

int main()
{
    PhoneNumber phone; // create object phone

    std::cout << "Enter phone number in form (123) 456-7890:" << std::endl;

    // cin >> phone invokes operator>> by implicitly issuing the non-member
    // function call operator>>( cin, phone )
    std::cin >> phone;
    // phone >> std::cin invokes member function operator>> by implicitly issuing
    // the member function call operator>>( std::cin, phone )
    //phone >> std::cin;
    
    std::cout << "The phone number entered was: ";
    
    // cout << phone invokes operator<< by implicitly issuing the non-member function
    // call operator<<( cout, phone )
    std::cout << phone << std::endl;
    // phone << std::cout invokes member function operator<< by implicitly issuing
    // the member function call operator<<( std::cout, phone )
    //phone << std::cout << std::endl;

    return 0;
}
