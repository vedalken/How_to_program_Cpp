// main.cpp
// Sort numbers in ascending order using 
// bubble sort or modified bubble sort.
#include <iostream>
#include <iomanip>
#include "sortFunctions.h"
using std::cout;
using std::endl;
using std::setw;

// function prototype
void displayArray( const int array[], const int arraySize );

int main()
{
	const int nArraySize = 30000; // array size
	int anArray[ nArraySize ]; // declare array
	
	// fill array with elements
	for ( int i = 0; i < nArraySize; ++i )
		anArray[ i ] = nArraySize - i;

	// display array
	//displayArray( anArray, nArraySize );
	
	// sort algorithm in ascending order
	sortInsert( anArray, nArraySize );
	
 	cout << "Sort:" << endl;
	//displayArray( anArray, nArraySize );

	return 0;	
}// end main

void displayArray( const int array[], const int arraySize )
{
	for ( int index = 0; index < arraySize; ++index )
		cout << setw( 3 ) << array[ index ];
	
	cout << "\n"; // new line
}//end displayArray function
