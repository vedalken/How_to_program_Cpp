// main.cpp
// Calculate power of integer number.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// Function recursively calculates integer power
long power( int base, int exponent )
{
	if (exponent == 1) {
		return base;
	}
	else if (exponent == 0) {
		return 1;
	}
	else {
		return base * power( base, exponent-1 );
	}
}//end power function

int main()
{
	cout << "Calculate power of number.";	
	cout << "\nbase: ";
	int base;
	cin >> base;
	
	cout << "exponent: ";
	int exp;
	cin >> exp;

	cout << "\n" << base << "^" << exp << " = " << power( base, exp ) << endl;

	return 0;	
}
