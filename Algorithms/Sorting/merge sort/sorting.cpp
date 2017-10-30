#include "sorting.h"
using namespace std;

// merge two data sets into array
//
void merge( double *array, const int lo, const int mid, const int hi, double *aux )
{
	int i = lo;
	int j = mid + 1;

	// copy array into auxiliary array
	for ( int index = lo; index <= hi; ++index )
		aux[ index ] = array[ index ];

	for ( int k = lo; k <= hi; ++k )
	{
		if ( i > mid )                   array[ k ] = aux[ j++ ];
		else if ( j > hi )               array[ k ] = aux[ i++ ];
		else if ( aux[ j ] < aux[ i ] )  array[ k ] = aux[ j++ ];
		else                             array[ k ] = aux[ i++ ];
	}

}

// merge sort
void mergesortHelper( double *array, const int lo, const int hi, double *aux )
{
	int arraySize = hi - lo + 1;	// array size (note: + 1 !)
	int low  = lo;                  // index of the first element in the array
	int mid  = lo + ( hi - low )/2; // index of the middle element int the array
	int high = hi;                  // index of the last element in the array
	
	// split data set into two halves
	// until a subarray contains only one element
	if ( arraySize <= 1 ) 
		return;
	
	// split array
	mergesortHelper( array, low, mid, aux);     // split array into left half
	mergesortHelper( array, mid+1, high, aux ); // split array into rigth half
	
	// merge two sorted subarrays into one array 
	merge( array, low, mid, high, aux ); 
}

void mergesort( double *array, const int lo, const int hi )
{
	int arraySize;
	arraySize = hi - lo + 1;

	// auxiliary array
	double *aux = new (nothrow) double [ arraySize ];
	
	if ( !aux )
	{
		cout << "\nMemory allocation failure or 0!\n";
		return;
	}
	
	// initialize pointer
	for ( int i = 0; i < arraySize; ++i )
		aux[ i ] = 0;

	// merge sort algorithm
	mergesortHelper( array, lo, hi, aux );
	
	// free memory
	delete[] aux;
	aux = 0;
}
