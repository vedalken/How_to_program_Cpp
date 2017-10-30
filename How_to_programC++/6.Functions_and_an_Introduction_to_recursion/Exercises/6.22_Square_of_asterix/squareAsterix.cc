// squareAsterix.cc
// Display square of asterixes (default). Maximal square is 100x100!
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Display square of asterixes (by default parameter)
// Side maximal value is 100.
void displaySquare( int side, const char sybmol = '*' );

int main()
{
	cout << "Side of square (max = 100): ";
	int squareSide;
	cin >> squareSide;
	cout << endl;

	// display square of asterixes, so second parameter is used
	// as default
	displaySquare( squareSide );

	return 0;
}

// Display square of asterixes (by default parameter)
void displaySquare( int side, const char symbol )
{
	const int maxSideLength = 60; // maximal side length
	// Change side length to maximal value
	// Validation point.
	if ( side > maxSideLength ) 
	{
		cout << "\nSide is larger than maximal side length " << maxSideLength << endl;
		cout << "side length is changed to maximal length." << endl;
		side = maxSideLength;
	}

	// Print square of characters (default is *)
	for ( int i=0; i < side; ++i ) 
	{
		for ( int j=0; j < side; ++j ) 
		{
			cout << symbol << " "; // display character
		}
		// new line when reached side lenght 
		cout << "\n";
	}

	// print new line
	cout << "\n";
}
