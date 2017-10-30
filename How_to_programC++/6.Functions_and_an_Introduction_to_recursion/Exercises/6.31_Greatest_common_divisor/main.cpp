// main.cpp
// Calculate greatest common divisor.
#include <iostream>
#include "func.h"
using std::cout;
using std::endl;
using std::cin;

// Program execution begins with main
int main()
{
	cout << "Enter two integer numbers: ";
	int number1;
	int number2;
	cin >> number1 >> number2; // read two input integers

	int greatestCommonDivisor;
	greatestCommonDivisor = gcd( number1, number2 );

	cout << "\nGreatest common divisor: " << greatestCommonDivisor << endl;

	return 0;	
}
