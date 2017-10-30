// main.cpp
// Compute factorial for nonegative integer number.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// function prototype
long 	factorial(unsigned n); 				// factorial function n! 
double	exponential(double x, double prec);	// exponential function exp(x)

// Program execution begins with main
int main()
{
	double roundError; // set round error for computing function values
	double argument;

	cout << "Enter argument and precision calculation: ";
	cin >> argument >> roundError;
		
	cout << endl;
	cout << "Exp = " << exponential( argument,roundError ) << endl;
	cout << endl;

	return 0;
} // end main


