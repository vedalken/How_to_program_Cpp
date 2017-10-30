#include <iostream>
using std::cout;
using std::endl;
#define ARRAY_SIZE 50

#if !defined ARRAY_SIZE
#define ARRAY_SIZE 100			// define array size
#define TABLE_SIZE ARRAY_SIZE	// define table size
#else
#define TABLE_SIZE ARRAY_SIZE	
#endif

int main()
{
	std::cout << TABLE_SIZE << std::endl;

	return 0;	
}
