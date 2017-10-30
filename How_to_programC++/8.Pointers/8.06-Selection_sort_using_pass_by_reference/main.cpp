// main.cpp
// Program sorts array of integer numbers with
// selection sort (ascending order).
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::setw; // iomanip

void printArray( const int* const, const int );
void selectionSort( int* const, const int );
void swap( int* const, int* const );
int main()
{
	const int arraySize = 10;
	int array[ arraySize ] = { 
		98, 13, 1, -5, 74, 32, 11, 85, 115, 50 };
	printArray( array, arraySize );	
	selectionSort( array, arraySize );
	printArray( array, arraySize );	
	return 0;	
}

///
/// print array
void printArray( const int* const array, const int size )
{
	for ( int i = 0; i < size; ++i )
		cout << setw(5) << array[i];
	cout << "\n";
}

///
/// selection integer sort (ascending order)
void selectionSort( int* const array, const int size )
{
	for ( int element = 0; element < size-1; ++element )
	{
		// index of current smallest element
		int smallIndex = element;
		for ( int index = element+1; index < size; ++index )
		{
			if ( array[ index ] < array[ smallIndex ] )
				smallIndex = index; 
		}

		// smallest element found, now swap values with element
		// at position "element", addresses remains unchanged
		swap( &array[ element ], &array[ smallIndex] );	
	}
}

///
/// swap two elements; values are changed but not address
void swap( int* const aPtr, int* const bPtr )
{
	int hold = *aPtr; 
	*aPtr = *bPtr;
	*bPtr = hold;
}
