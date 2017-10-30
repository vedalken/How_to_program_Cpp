// 2dmatrix.cpp
// Declare matrix 8x8 (two dimenstional array)
// and display each element.
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip

int main()
{
	const int nArraySize = 8;
	int nArray[ nArraySize ][ nArraySize ]; // 2D array
	
	// initialize array by multiplying row and column
	// index
	for ( int i = 0; i < nArraySize; ++i )
	{
		for ( int j = 0; j < nArraySize; ++j )
		{
			nArray[i][j] = i * j;
		}
	}

	// display two dimensional array
	for ( int nRow = 0; nRow < nArraySize; ++nRow ) 
	{	
		for ( int nColumn = 0; nColumn < nArraySize; ++nColumn )
		{
			cout << setw(4)
				<< "[" << setw(2) << nRow << setw(2) << "]" 
				<< "[" << setw(2) << nColumn << setw(2) << "]" << "=";
			cout << setw(3) << nArray[ nRow ][ nColumn ];
		}

		cout << endl; // new line
	}
	
	return 0;	
}//end main
