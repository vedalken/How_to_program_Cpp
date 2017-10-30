// printValues.cpp
// Use default function parameter list for data manipulation.
#include <iostream>
using namespace std;

// Function displays two values, second parameter has default
// value
void printValues( int value1, int value2=10 ) 
{
	cout << "1st value: " << value1 << ", 2nd value: " << value2 << endl;		
}

int main()
{
	printValues(1); 	// value1 = 1, value2 passed default value
	printValues(1,5);	// both values are passed; default value is overriden

	return 0;	
}
