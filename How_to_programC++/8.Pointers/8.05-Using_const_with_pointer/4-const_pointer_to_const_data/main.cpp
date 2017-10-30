// main.cpp
// Attempting to modify constant data
// with constant pointer.
#include <iostream>
int main()
{
	int x = 5, y = 0;

	// constant pointer nPtr to integer constant
	// pointer always points to the same location;
	// the integer at that location cannot be modified
	const int* const nPtr = &x;

	// display address and value at that address
	std::cout << nPtr << std::endl;
	std::cout << *nPtr << std::endl;

	*nPtr = 8; // error: *nPtr is const; cannot assign new value
	nPtr = &y; // error: nPtr is const; cannot assign new address

	return 0;	
}
