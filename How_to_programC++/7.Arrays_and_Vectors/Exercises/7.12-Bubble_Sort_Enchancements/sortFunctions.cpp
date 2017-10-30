// sortFuctions.cpp
// Sorting implementation algorithms
// Algorithms sort in ascending order
#include <iostream>
#include "sortFunctions.h" // functions declaration

////
////
//// swap two elements
inline void swap( int & a, int & b ) {
	int tmp = b;
	b = a; 
	a = tmp;
}// end swap function

////
////
//// sort array with bubble sort
void sortBubble( int anArray[], const int nArraySize )
{
	// Sort array with bubble sort
	// Last pass is nArraySize-1, because last element is already 
	// sorted!
	for ( int i = 0; i < ( nArraySize-1 ); ++i )
	{
		for ( int j = 1; j < nArraySize; ++j )
		{
			// swap each element - this is not necessary!
			if ( anArray[ j-1 ] > anArray[ j ] )
				swap( anArray[ j ], anArray[ j-1 ] );
		}
	}
}// end bubbleSort function

////
////
//// modified bubble sort
void sortBubbleM( int anArray[], const int nArraySize )
{
	// sort array with bubble sort
	// last pass is nArraySize-1, because last element is already 
	// sorted!
	for ( int i = 0; i < ( nArraySize-1 ); ++i )
	{
		// count number of swaps - appropriate for already sorted
		// array, or partialy sorted array
		int nCountSwaps = 0;

		// compare only elements, which are not sorted -there are
		// on each pass, nArraySize-i elements to compare
		for ( int j = 1; j < nArraySize-i; ++j )
		{
			// ascending order sort
			if ( anArray[ j-1 ] > anArray[ j ] )
			{
				// swap elements
				swap( anArray[ j ], anArray[ j-1 ] );
				++nCountSwaps;
			}
		}

		// check if array is already sorted, to skip 
		// next pass
		if ( nCountSwaps == 0 )
		{
			std::cout << "Skipped next pass!" << std::endl;
			break;
		}
	}
}// end bubbleSort function

////
////
//// selection sort
void sortSelect( int anArray[], const int nArraySize )
{
	for ( int i = 0; i < (nArraySize-1); ++i ) 
	{
		int nSelectIndex = i; // swap element index

		for ( int j = i; j < nArraySize; ++j )
		{
			if ( anArray[ nSelectIndex ] > anArray[ j ] )
				nSelectIndex = j; // save new element position
		}
		
		// swap element to new position
		if ( nSelectIndex != i )
			swap( anArray[ nSelectIndex ], anArray[ i ] );
	}
}//end sortSelect function

////
////
//// insertion sort
void sortInsert( int anArray[], const int nArraySize )
{
	// skip first element - no need to swap with no one
	for ( int i = 1; i < nArraySize; ++i ) 
	{
		int nItemIndex = i; 				// item index
		int nItem = anArray[ nItemIndex ]; 	// item value
		
		// shift elements by 1 left or right before final
		// element is inserted in proper array position
		while ( nItemIndex > 0 && anArray[ nItemIndex-1 ] > nItem ) 
		{
			anArray[ nItemIndex ] = anArray[ nItemIndex-1 ];
			--nItemIndex;
		}
	
		// final element position
		anArray[ nItemIndex ] = nItem;
	}
}//end sortInsert function
