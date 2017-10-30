// main.cpp
// Determine if number is palindrome i.e.
// 12321 is palindrome, because same digit pattern of backward and forward.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int number;
	cout << "Enter 5 digit number: ";
	cin >> number;

	// Determine if palindrom
	int number1, number2; 	// first and second most significant digit
	int reminder;			// reminder after division

	number1	= number / 10000;	// first digit of a number
	reminder = number % 10000;	// reminder after division
	number2 = reminder / 1000;

	int last2Numbers;		// last two digit number
	int number4, number5; 	// last two digit of number

	last2Numbers = number % 100;
	number4 = last2Numbers / 10;
	number5 = last2Numbers % 10;

	// Check if number is palindrome
	// First significant digit must be equal to last digit,
	// second significant digit must be equal to penultimate digit.
	if (number1 == number5) {
		if (number2 == number4) {
			cout << "Number is palindrome." << endl;	
		}
	}
	else if (number2 == number4) {
		if (number1 == number5) {
			cout << "Number is palindrome." << endl;
		}
	}
	else {
		cout << "Number is NOT palindrome." << endl;
	}

	return 0;	
}
