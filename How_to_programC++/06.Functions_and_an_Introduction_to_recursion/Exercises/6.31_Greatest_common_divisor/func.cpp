// func.cpp
// Function implementations.
#include <cstdlib>
#include "func.h"
using std::exit; // cstdlib

// Calculate greatest common divisor (gcd)
int gcd( int number1, int number2 )
{
	// Determine smaller value, from where greatest common divisor
	// is calculated, and also determine greater 
	int smallerNumber = 0;
	int greaterNumber = 0;
	
	if (number1 > number2) 
	{
		smallerNumber = number2;
		greaterNumber = number1;
	} 
	else {
		smallerNumber = number1;
		greaterNumber = number2;
	}

	// check for non-zero value
	if (smallerNumber == 0) 
		exit(0);
	
	int commonDivisor = 0; // greatest common divisor

	for (int i = 1; i < smallerNumber; ++i)
	{
		if (smallerNumber % i == 0)
			commonDivisor = smallerNumber / i;
		else {
			continue; // next divisor
		}

		if (greaterNumber % commonDivisor == 0) // check for gcd
			return commonDivisor; 				// gcd is found
	}//end for loop

	// Trivial greatest common divisor
	return 1; 
}//end gcd function
