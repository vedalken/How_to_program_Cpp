// main.cc
// Find minimum of three floating-point, double precision numbers.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

double findMinimum( double, double, double ); // function prototype

int main()
{
	// User input three double numbers
	cout << "Enter three double values: ";
	double val1;
	double val2;
	double val3;
	cin >> val1 >> val2 >> val3;

	// Display the smallest of those three entered by user
	cout << "minimal: " << findMinimum( val1, val2, val3 ) << endl;
	
	return 0;
}

// Function determines minimum of three double numbers
double findMinimum( double a, double b, double c )
{
	double minValue = a;
	
	// Test the smallest value, and return it
	if (b < minValue)
		minValue = b;
	
	if (c < minValue)
		minValue = c;

	return minValue;
}
