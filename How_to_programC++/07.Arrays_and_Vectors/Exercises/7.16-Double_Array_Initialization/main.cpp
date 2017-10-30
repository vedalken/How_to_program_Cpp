// main.cpp
// Initialize two dimensional array.
int main()
{
	const int nRows = 3;	// number of rows
	const int nColumns = 5;	// number of columns
	int anArray[ nRows ][ nColumns ]; // declare 2D array

	// initialize 3x5 matrix to zero
	for ( int row = 0; row < nRows; ++row )
		for ( int column = 0; column < nColumns; ++column )
			anArray[ row ][ column ] = 0;

	return 0;	
}
