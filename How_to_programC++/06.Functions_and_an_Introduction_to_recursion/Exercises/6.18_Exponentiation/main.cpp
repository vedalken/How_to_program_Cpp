// main.cpp
// Calculate power of integer number:
// 		
// 		base ^ exponent
//
#include <iostream>
using namespace std;

// Calculate integer power for integer exponents
long integerPower( int base, int exponent );

int main()
{
	cout << "Calculate power(exponent) of base number i.e base^exponent." << endl;
	cout << "Enter nonegative integer base and exponent: "; // display message to user
	int base;
	int exponent;
	cin >> base >> exponent; // read user input

	// Display result
	cout << "Result: " << integerPower( base, exponent ) << endl;

	return 0;	
}

// Compute integer power with integer base and
// integer exponent e.g. base^exponent = 3^3 = 3*3*3
long integerPower( int base, int exponent )
{
	long result = base; // initialize value to base value (initial value)
	
	// Loop (exponent-1) times - one integer is already used
	// in initialization result
	// Multiply as many times as the (exponent-1)
	for (int i = 1; i < exponent; ++i)
		result *= base;

	return result;
}// destroy local variables: result, exponent, base
