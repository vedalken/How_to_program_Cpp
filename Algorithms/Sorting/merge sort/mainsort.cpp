#include <iostream>
#include <new>
#include <cstdlib>
#include <ctime>
#include "sorting.h"
#define PRINT_VEC
#undef PRINT_VEC
using namespace std;

int main()
{
	int arraySize;
	do
	{
		cout << "How many number is wish to sort? ";
		cin >> arraySize;
	} while( arraySize < 1 );
	

	double *ptrArray = new (nothrow) double [ arraySize ];
	if ( !ptrArray )
	{
		cout << "\nMemory allocation failure!\n";
		return -1;
	}

	// generate a seed
	srand( time(0) ); 	

	// generate random numbers
	for ( int i = 0; i < arraySize; ++i )
		ptrArray[ i ] = 1 + rand() % arraySize;
#ifdef PRINT_VEC
	// print initial array
	printArray( ptrArray, arraySize );
#endif
	// merge sort array
	mergesort( ptrArray, 0, arraySize - 1 );
	//selectionSort( ptrArray, arraySize );
#ifdef PRINT_VEC
	// print sorted array
	printArray( ptrArray, arraySize );
#endif
	
	delete[] ptrArray;
	ptrArray = 0;
	
	return 0;	
}
