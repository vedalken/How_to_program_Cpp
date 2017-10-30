// main.cpp
// Function template maximum test program.
#include <iostream>
#include "maximum.h"
using std::cout;
using std::endl;
using std::cin;

int main()
{
	// Demonstrate maximum with three int values
	int int1, int2, int3;
	cout << "\nInput three integer numbers: ";
	cin >> int1 >> int2 >> int3;

	// Function template call with integer arguments 
	// Compiler replaces in function definition type T with int
	cout << "Maximum integer number is " << maximum( int1, int2, int3 ) 
		<< endl;

	// Demonstrate maximum with three double values
	double double1, double2, double3;
	cout << "\nInput three double numbers: ";
	cin >> double1 >> double2 >> double3;

	// Compiler replaces in function definition type T with double
	cout << "Maximum double number is " << maximum( double1, double2, double3 ) 
		<< endl;

	// Demonstrate maximum with three char values
	char char1, char2, char3;
	cout << "\nInput three characters: ";
	cin >> char1 >> char2 >> char3;

	// Compiler replaces in function definition type T with char
	cout << "Maximum char is " << maximum( char1, char2, char3 ) << endl;

	return 0;	
}
