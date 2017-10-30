// main.cpp
// Sort elements with bucket sort.
// sort only positive numbers
#include "sort.h"

int main()
{
	// number of elements
	const int numOfElements = 5;
	int array[ numOfElements ] = { 45, 633, 1, 86, 21 };
	
	bucketSort( array, numOfElements );
	printArray( array, numOfElements );

	return 0;
}
