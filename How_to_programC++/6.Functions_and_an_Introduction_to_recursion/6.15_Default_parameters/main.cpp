// main.cpp
// Calculate box volume. Function call boxVolume with default
// parameters.
#include <iostream>
using std::cout;
using std::endl;

// Function prototype with three default arguments (compiler wont complain!)
// Default arguments are passed when function call is performed
int boxVolume( int length=1, int width=1, int height=1 );
// or
// int boxVolume( int =1, int =1, int =1 );
// Disadvantage of last use is box sides are unknown.

int main()
{
	cout << "\nBox sides (length, width, height)\n\n";

	// Default argument are passed (by compiler)
	cout << "Box volume (1,1,1): "<< boxVolume() << endl;
	
	// Change(override) length to 5, use default width and height 
	cout << "\nBox volume (5,1,1): " << boxVolume( 5 ) << endl;

	// Change length and width, use default height
	cout << "\nBox volume (5,6,1): " << boxVolume( 5, 6 ) << endl;

	// Override all default parameters!
	cout << "\nBox volume (5,6,7): " << boxVolume( 5, 6, 7 ) << endl;

	return 0;	
}

// Function calculates box volume with default parameters
int boxVolume( int length, int width, int height ) 
{
	return length * width * height; // calculate box volume
}
