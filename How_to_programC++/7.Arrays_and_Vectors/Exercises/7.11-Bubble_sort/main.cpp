// main.cpp
// Sort numbers in increasing order using bubble sort.
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

// function prototype
void displayArray( const int array[], const int arraySize );
void swap( int &a, int &b );

int main()
{
	const int nArraySize = 10; // array size
	int anArray[ nArraySize ] = { 11, -6, 3, 6, 7, 5, 1, 4, 2, 8 };
	
	// display array
	displayArray( anArray, nArraySize );
	
	// sort array with bubble sort - comparing pairs.
	for ( int i = 0; i < nArraySize; ++i )
	{
		for ( int j = 1; j < nArraySize; ++j )
		{
			// swap each element - this is not necessary!
			if ( anArray[ j-1 ] > anArray[ j ] )
				swap( anArray[ j ], anArray[ j-1 ] );
		}
	}
	
 	cout << "Bubble sort:" << endl;
	displayArray( anArray, nArraySize );

	return 0;	
}// end main

void displayArray( const int a[], const int arrySize )
{
	for ( int index = 0; index < arrySize; ++index )
		cout << setw( 3 ) << a[ index ];
	
	cout << "\n"; // new line
}//end displayArray function

// swap elements
void swap( int & a, int & b )
{
	int tmp = 0; // temporary variable
	tmp = b;
	b = a;
	a = tmp;
}// end swap function
