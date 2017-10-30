// sorting.h
//
#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


template < typename T >
void printArray( T *array, const int size )
{
	for ( int i = 0; i < size; ++i )
	{
		// print output in ten columns 
		if ( i % 9 == 0 )
			cout << '\n';
		
		cout << setw( 4 ) << array[ i ];
	}
	cout << '\n';
}
// sort array
template < typename T >
void selectionSort( T *array, const int size )
{
	for ( int i = 0; i < size; ++i )
	{
		int index = i; // currect position

		// find smallest value
		// store index of that element
		// don't compare with its self -> j start with i+1
		for ( int j = i+1; j < size; ++j )
		{
			// store index of current the smallest value
			if ( array[ j ] < array[ index ] )
				index = j;
		}

		// swap values 
		// smaller value is swaped with the greater value
		swap( array[ i ], array[ index ] );
	}
}

void merge( double *, const int lo, const int mid, const int hi, double *aux );
void mergesortHelper( double *, const int lo, const int hi, double *aux );
void mergesort( double *, const int lo, const int hi );
#endif
