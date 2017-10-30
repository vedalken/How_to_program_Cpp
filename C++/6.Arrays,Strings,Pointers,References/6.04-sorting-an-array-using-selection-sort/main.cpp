// main.cpp
// Sort array elements with selection sort
// in ascending or discending order.
#include <iostream>
#include <iomanip>
#include <algorithm>
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip
using std::swap; // algorithm

// function prototype
void displayArray( const int array[], int arraySize ); 

int main()
{
	const int nArraySize = 5;
	int anArray[ nArraySize ] = { 30, 50, 20, 10, 40 };
	char chSortOrder = 'd'; // ascending order ('d' descending order)

	// display array before sorting
	displayArray( anArray, nArraySize );

	// selection sort
	for ( int nIndex = 0; nIndex < nArraySize; ++nIndex )
	{
		// current the smallest (or biggest) element has 
		// index nSmallestIndex
		int nSmallestIndex = nIndex ;

		// nIndex elements are already sorted
		// compare all elements
		for ( int i = nIndex; i < nArraySize; ++i )
		{
			if ( chSortOrder == 'a' ) // ascending order
			{
				if ( anArray[ nSmallestIndex ] > anArray[ i ] )
					nSmallestIndex = i; // current smallest i-th element 
			}
			else // descending order
			{
				if ( anArray[ nSmallestIndex ] < anArray[ i ] )
					nSmallestIndex = i; // current largest i-th element
			}
		}

		// swap elements with index nIndex and smallestIndex
		swap( anArray[ nIndex ], anArray[ nSmallestIndex ] );
	}//end for loop

	// display array after sorting
	displayArray( anArray, nArraySize );

	return 0;	
}

// display elements in array
void displayArray( const int a[], int nSize )
{
	for ( int i = 0; i < nSize; ++i )
		cout << setw(4) << a[i];

	cout << endl; // new line
}
