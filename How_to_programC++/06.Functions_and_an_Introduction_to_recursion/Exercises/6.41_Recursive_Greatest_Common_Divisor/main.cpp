// main.cpp
// Recursive calculation greatest common divisor.
#include <iostream>
using namespace std;

int gcd( int a, int b );

int main()
{
	cout << "Enter first number bigger than the second enetered: ";
	int number1;
	int number2;
	cin >> number1 >> number2;

	// Display greatest common divisor
	cout << "gcd: " << gcd( number1, number2 ) << endl;

	return 0;	
}
