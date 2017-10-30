// exponent.cpp
// Function calls exponent function for calculating
// exponent value.
#include <iostream>
using std::cout;
using std::endl;

// Function prototype
int exponent(int base, int exp);

// Program execution begins with main
int main()
{
	int base = 2;
	int exp	= 8; 
	cout << base << "^" << exp << " = " << 
		exponent(base,exp) << endl;

	return 0;
}

// Function calculate exponent value exp of a base
int exponent( int base, int exp )
{
	int value = 1;

	//for (int i=0; i<exp; ++i)
	//	value *= base;
		
	// or using while statement
	{
		int i=0;

		while (i<exp) {
			value *= base;
			++i;
		}
	} // terminate scope variable i

	return value;
}// end exponent 
