// main.cpp
// Display input number in reverse (digit) order.
#include <iostream>
#include <cmath>
using std::cout; // iostream
using std::endl;
using std::cin;
using std::fabs; // cmath

void reverseDigits( int ); // function prototype

int main()
{
	cout << "Enter positive integer: ";
	int integer;
	cin >> integer;
	
	cout << "\nReverse order: ";
	integer = fabs( integer ); // positive value
	reverseDigits( integer );
	
	cout << "\n"; // new line

	return 0;
}//end main

// Display integer number in reverse order
void reverseDigits( int number )
{
	int oldValue = 0; 	// previous number, before division
	int digit = 0;		// number digit

	while( oldValue != number )
	{
		oldValue = number; 
		digit = number % 10;	// number digit
		number /= 10;			// new number
		
		// Check if you have all digits
		// When oldValue and number are equal, then this is
		// last digit in use.
		if( oldValue == number )
			break;

		cout << digit; // display each digit
	} 
}// destroy digit, oldValue, number; end function
