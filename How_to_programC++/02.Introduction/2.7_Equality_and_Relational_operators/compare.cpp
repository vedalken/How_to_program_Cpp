// compare.cpp
// Comparing integers using if statements, relational operators
// and equality operators.

#include <iostream> // allow program to perform input and output

using std::cout; 	// program uses cout
using std::endl;	// program uses endl
using std::cin;		// program uses cin

// function main begins program execution
int main()
{
	int number1;	// first integer to compare
	int number2;	// second integer to compare

	cout << "Enter two integers: ";	// prompt user to enter data
	cin >> number1 >> number2; 		// read two integers from user

	if (number1 == number2)
		cout << number1 << " == " << number2 << endl;
	
	if (number1 != number2)
		cout << number1 << " != " << number2 << endl;
	
	if (number1 > number2)
		cout << number1 << " > " << number2 << endl;

	if (number1 < number2)
		cout << number1 << " < " << number2 << endl;

	return 0;
} // end function main
