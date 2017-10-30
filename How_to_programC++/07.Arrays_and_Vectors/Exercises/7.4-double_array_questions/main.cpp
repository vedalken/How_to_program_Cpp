// main.cpp
// Declare two dimensional array "table".
#include <iostream>
#include <iomanip>
using std::cout; //iostream
using std::endl;
using std::setw; //iomanip

int main()
{
	const int nArraySize = 3;
	int anTable[ nArraySize ][ nArraySize ] = 
		{ { 1, 8 }, { 2, 4, 6 }, { 5 } };
	
	// initialize array suming element subscripts
	//for ( int i = 0; i < nArraySize; ++i )
	//{
	//	for ( int j = 0; j < nArraySize; ++j )
	//		anTable[ i ][ j ] = i + j;
	//}
	
	// display twodimensional array
	for ( int i = 0; i < nArraySize; ++i )
	{
		for ( int j = 0; j < nArraySize; ++j )
			cout << setw(3) << anTable[ i ][ j ];

		cout << endl; // new line
	}

	return 0;	
}//end main
