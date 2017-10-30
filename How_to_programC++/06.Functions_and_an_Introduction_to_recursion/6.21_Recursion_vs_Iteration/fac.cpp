// fac.cpp
// Program calculates factorials iteratively.
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip

unsigned long factorial( unsigned long );

int main()
{
	// Display factorial for first ten numbers
	for (int i=0; i <= 10; ++i)
		cout << setw(2) << i << "! = " << factorial( i ) << endl;

	return 0;
}

// Factorial calculation (iteratively!)
unsigned long factorial( unsigned long number )
{
	unsigned long result = 1; // initial value, and final result 

	// calculate factorial
	for (unsigned i = number; i > 0; --i)
		result *= i; // multiply every value (e.g. 3! = 3*2*1)
	
	return result;
}
