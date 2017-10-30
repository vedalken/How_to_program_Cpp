// sum.cpp
// Program calls function that sums integer numbers.
#include <iostream>
using std::cout;
using std::endl;

int sum( int value );

// Main program
int main()
{
	int number = 10;
	
	cout << "Sum from 1 to " << number << " = " << sum(number) << endl;
	
	for (int i=9; i>=0; --i)
		cout << i << " ";

	return 0;
}
// end main

// Function definition for sum integer values
int sum(int value)
{
	int sumValue = 0; // initial value if value is zero

	// Sum numbers from zero to number value
	for (int i=1; i <= value; sumValue += i, ++i);

	return sumValue;
}// end sum function
