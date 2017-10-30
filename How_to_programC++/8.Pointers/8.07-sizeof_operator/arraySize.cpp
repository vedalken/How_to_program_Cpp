// arraySize.cpp
// Use sizeof operator on array and pointer.
#include <iostream>
using std::size_t;

size_t getSize( const char* );
int main()
{
	const int size = 10;
	char array[ size ] = {};
	
	std::cout << "\nNumber of bytes in array: " << sizeof array;
	std::cout << "\nNumber of bytes by getSize: " 
		<< getSize( &array[0] ) << std::endl;
	return 0;
}

// return size of ptr
size_t getSize( const char* ptr )
{
	return sizeof ptr;	
}
