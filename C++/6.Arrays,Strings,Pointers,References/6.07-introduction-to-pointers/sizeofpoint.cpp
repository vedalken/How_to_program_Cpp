// sizeofpoint.cpp
// Determines size of pointers.
#include <iostream>
int main()
{
	char* chPtr;
	int* nPtr;
	struct Something {
		int nX, nY, nZ;
		double dX;
	};
	Something sPtr;

	std::cout << sizeof( chPtr ) << std::endl;
	std::cout << sizeof( nPtr ) << std::endl;
	std::cout << sizeof( sPtr ) << std::endl;
	std::cout << sizeof( double ) << std::endl;
	std::cout << sizeof( int ) << std::endl;

	return 0;	
}
