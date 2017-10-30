#include <iostream>
//#define INT_2_BYTES for machines with 2 bytes int!
// platform indepenedent coding
#ifndef INT_2_BYTES
typedef char int8;
typedef int int16;
typedef long int32;
#else
typedef char int8;
typedef short int16;
typedef int int32;
#endif

int main()
{
	int16 nNumberOfCars = 5242;
	
	std::cout << "Int in bytes:" << sizeof(int) << std::endl;
	std::cout << nNumberOfCars << std::endl;

	return 0;
}

