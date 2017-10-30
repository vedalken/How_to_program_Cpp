#include <iostream>
#include "Array.h"

void outputArray( const Array& ); // function prototype

int main()
{
    Array integers1( 7 );
    outputArray( integers1 );

    // NO ERROR: remove explicit keyword from the constructor and rebuild!
    //outputArray( 3 ); // equivalent to: outputArray( Array( 3 ) );

    // Compile ERROR: with explicit conversion constructor
    outputArray( Array( 3 ) );

    return 0;
}

void outputArray( const Array& arrayToOutput )
{
    std::cout << "The Array received has " << arrayToOutput.getSize()
        << " elements. The contents are:\n" 
        << arrayToOutput << std::endl;
}
