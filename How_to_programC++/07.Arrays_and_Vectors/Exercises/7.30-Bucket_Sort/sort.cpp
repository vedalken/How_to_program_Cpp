#include <iostream>
#include <cmath>
#include "sort.h"
using std::cout; // iostream
using std::endl;
using std::pow; // cmath

// bucket sort algorithm
void bucketSort( int array[], const int arraySize )
{
	int maximal = -1;
	// determine maximal number
	for ( int i = 0; i < arraySize; ++i )
	{
		if ( array[i] > maximal )
			maximal = array[i];
	}
	
	// determine maximal number of digits
	int totalDigits  = maxDigits( maximal );
	const int rows = 10;
	const int cols = arraySize;

	int bucketArray[ cols ][ rows ];
	// initialize array to -1
	init2Darray( bucketArray, arraySize );

	for ( int digit = 1; digit <= totalDigits; ++digit )
	{
		// loop over array elements and fill two dimensional array
		for ( int element = 0; element < arraySize; ++element )
		{
			int value = array[ element ];
			
			// put array element into 2D array with row subscript
			// "row2Darray"
			int row2D = getDigit( value, digit );
			int col2D = 0; //=get2Dcol( bucketArray, arraySize, row2D );
			for ( int col1 = 0; col1 < arraySize; ++col1 )
			{
				// find legal place
				if ( bucketArray[ col1 ][ row2D ] < 0 )
				{
					col2D = col1;
					break;
				}
			}
			bucketArray[ col2D ][ row2D ] = value;
		}
		
		int tmpArray[ arraySize ];
		for ( int i = 0; i < arraySize; ++i )
			tmpArray[ i ] = 0;

		// gather all elements in 2D array and put into array
		int tmp2D = 0;
		// count elements
		int count = 0;

		for ( int row2D = 0; row2D < 10; ++row2D )
		{
			for ( int col2D = 0; col2D < arraySize; ++col2D )
			{
				tmp2D = bucketArray[ col2D ][ row2D ];
				if ( tmp2D > 0 )
				{
					tmpArray[ count ] = tmp2D;
					++count;
				}
				else
					break; // skip not filled elements
			}
		}
		
		for ( int i = 0; i < arraySize; ++i )
			array[ i ] = tmpArray[ i ];
		
		// re-initialize array
		init2Darray( bucketArray, arraySize );
	}
}

///
/// initialize two dimensional array
void init2Darray( int array[][10], const int arraySize ) {
	for ( int row = 0; row < 10; ++row )
		for ( int col = 0; col < arraySize; ++col )
			array[ col ][ row ] = -1;
}

/// return column position of legal move
int get2Dcol( int array[][10], const int arraySize, const int rowPosition )
{
	for ( int col = 0; col < arraySize; ++col )
	{
		// find legal place
		if ( array[ col ][ rowPosition ] > 0 )
			return col;
	}

	return 0;
}

/// collect all bucket number into array (overriding previous values)
void collectBuckets( int array2D[][10], int array1D[], const int arraySize )
{
	// temporary 2D value
	int tmp2D = 0;
	// count elements
	int count = 0;

	for ( int row2D = 0; row2D < 10; ++row2D )
	{
		for ( int col2D = 0; col2D < arraySize; ++col2D )
		{
			tmp2D = array2D[ col2D ][ row2D ];
			if ( tmp2D > 0 )
			{
				array1D[ count ] = tmp2D;
				++count;
			}
			else
				break; // skip not filled elements
		}
	}
}

/// return i-th digit of number
/// or returns "whichDigit"-th digit
int getDigit( int number, const int whichDigit ) 
{
	const int numOfDigits = maxDigits( number );
	int numberDigits[ numOfDigits ];
	for ( int i = 0; i < numOfDigits; ++i )
		numberDigits[ i ] = 0;
	
	getDigits( numberDigits, numOfDigits, number );
	
	if ( whichDigit > numOfDigits ) 
		return 0;
	else if ( whichDigit < 1 ) 
	{
		cout << "Digit starts counting from 1 not from 0!" << endl;
		return -1;
	}
	
	// digit counts from 1, not from 0
	// but first digit is filled in element 0 in array
	return numberDigits[ whichDigit-1 ];
}

/// split number into digits by filling array
/// with digits
void getDigits( int array[], const int arraySize, const int number )
{
	int totalDigits = maxDigits( number );
	
	if ( totalDigits != arraySize )
	{
		cout << "Array size does not match number of digits" << endl;
		return;
	}
	
	int tmpNumber = number;
	// array element 0 is filled with first digit, last element
	// with last digit of number
	for ( int digit = totalDigits; digit > 0; --digit )
	{
		array[ digit-1 ] = tmpNumber / pow( 10, digit-1 );
		tmpNumber %= static_cast<int>( pow( 10, digit-1 ) );
	}
}

/// determine maximal number of digits
int maxDigits( int number ) {
	const int factor = 10; // decimal factor
	int value = 1;
	int digit = 1;

	while ( value < number )
	{
		value *= factor;
		++digit;
	}
	// next after maximal digit are all 0
	// last digit is not used to count maximal non-zero
	// digits of number
	if ( value > 1 )
		--digit;

	return digit;
}

/// print array
void printArray( int array[], const int arraySize )
{
	for ( int i = 0; i < arraySize; ++i )
		cout << array[ i ] << " ";
	
	cout << "\n";
}
