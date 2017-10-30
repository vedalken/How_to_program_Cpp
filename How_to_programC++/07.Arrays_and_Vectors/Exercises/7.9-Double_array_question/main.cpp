// main.cpp
// Write integer 2x3 array.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	const int nRows = 2;	// number of rows
	const int nColumns = 3;	// number of columns

	// initialize 2D array to 0
	int t[ nRows ][ nColumns ] = { { 0, 0, 0 }, { 0, 0, 0 } };
	
	for ( int i = 0; i < nRows; ++i )
	{
		for ( int j = 0; j < nColumns; ++j )
			cout << t[ i ][ j ] << " ";

		cout << endl; // new line
	}
	// elements in row 1
	// t[ 1 ][ 0 ] 
	// t[ 1 ][ 1 ]
	// t[ 1 ][ 2 ]
	
	// elements in column 2 of t
	// t[ 0 ][ 2 ]
	// t[ 1 ][ 2 ]
	
	return 0;	
}// end main
