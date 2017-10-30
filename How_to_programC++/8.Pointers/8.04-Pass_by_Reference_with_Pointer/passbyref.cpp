// passbyref.cpp
// Calculating cube with pass-by-reference pointer.
// Variable is indirectly changed by pointer.
#include <iostream>
void cubeByReference( int* =nullptr );

int main()
{
	int number = 5;
	std::cout << "Original value: " << number;
	cubeByReference( &number );
	std::cout << "\nNew value: " << number << std::endl;
	
	return 0;	
}

void cubeByReference( int* nPtr ) 
{
	*nPtr = *nPtr * *nPtr * *nPtr;
}//nPtr goes out of scope, but value is changed!
