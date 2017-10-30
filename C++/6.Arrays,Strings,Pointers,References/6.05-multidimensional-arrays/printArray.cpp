// printArray.cpp
// Display two dimensional array.
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

int main()
{
	const int nNumRows = 10; // number of rows
	const int nNumCols = 10; // number of columns
	int anProduct[ nNumRows ][ nNumCols ]; // array of element products

	// initialize array as index element product
	// each element is product of array row and column index
	for ( int nRow = 0; nRow < nNumRows; nRow++ )
		for ( int nCols = 0; nCols < nNumCols; nCols++ )
			anProduct[ nRow ][ nCols ] = nRow * nCols;
	
	// display array
	for ( int nRow = 0; nRow < nNumRows; nRow++ )
	{
		for ( int nCols = 0; nCols < nNumCols; nCols++ )
			cout << setw(5) << anProduct[ nRow ][ nCols ];

		cout << endl; // new line
	}
		
	return 0;	
}
