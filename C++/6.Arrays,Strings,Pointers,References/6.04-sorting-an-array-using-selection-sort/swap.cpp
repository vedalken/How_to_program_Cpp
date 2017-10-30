// swap.cpp
// Swap two integer using swap function from 
// library <algorithm>
#include <iostream>
#include <algorithm>
using std::cout; // iostream
using std::endl;
using std::swap; // algorithm

int main()
{
	// declare two variables
	int x = 10, y = 20;

	cout << "Before swap: " << "x=" << x << ", " << "y=" << y << endl;
	
	// swap x and y
	swap( x, y );

	cout << "After swap: " << "x=" << x << ", " << "y=" << y << endl;

	return 0;	
}
