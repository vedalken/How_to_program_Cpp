// main.cpp
// Initializing multidimensional arrays.
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::setw; //iomanip

const int nRows = 2;	// number of rows
const int nColumns = 3; // number of columns

// function prototype
void displayArray( const int [][ nColumns ] ); // display 2D array

int main()
{	
	// initialize 2x3 matrix or two dimensional array
	int anArray1[ nRows ][ nColumns ] = { { 1, 2, 3 }, { 4, 5, 6 } };
	int anArray2[ nRows ][ nColumns ] = { 1, 2, 3, 4, 5 };
	int anArray3[ nRows ][ nColumns ] = { { 1, 2 }, { 4 } };
	
	// display arrays
	cout << "Values of array1 are: " << endl;
	displayArray( anArray1 );
	
	cout << "Values of array2 are: " << endl;
	displayArray( anArray2 );
	
	cout << "Values of array3 are: " << endl;
	displayArray( anArray3 );

	return 0;	
}//end main

// output 2D array 
// number of rows are left blank [], other must have specified
// array dimensions e.g. nColumns
void displayArray( const int anArray[][ nColumns ] )
{
	for ( int m = 0; m < nRows; ++m )
	{
		for ( int n = 0; n < nColumns; ++n )
			cout << setw(5) << anArray[m][n];	

		cout << endl; // new line
	}

	cout << endl; // new line
}//end displayArray function
