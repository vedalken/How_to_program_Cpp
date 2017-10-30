#include <iostream>
#include <string>
#include "String.h"

int main()
{
    String mystr("Some string");
    
    std::cout << "\nExplicit conversion String to const char*:\n";
    std:: cout << static_cast< const char * >( mystr ) << std::endl;

    // Compiler call the overloaded conversion operator function implicitly to 
    // create temporary objects
    std::cout << "\nImplicit convertion String to const char*:\n";
    std::cout << mystr << std::endl;
    
    return 0;
}
