// digits.cc
// Spliti number into digits with two spaces separated between each digit.
#include <iostream>
#include <cmath>
using namespace std;

void splitNumberIntoDigits( int );

// main program
int main() 
{
	cout << "Enter a number (< 99999): ";
	int number;
	cin >> number;

	// Split number into digits
	splitNumberIntoDigits( number );

	return 0;
}//end main program

// split integer number into digits
// every digit is separated with two spaces
void splitNumberIntoDigits( int number ) 
{
	int maxDigits = 5; // maximal number of digits
	
	// Exit loop if number is too large
	if ( number >= pow(10,maxDigits) ) {
		cout << "Number is to large!" << endl;
		cout << "Exit." << endl;
		return; 
	}

	{// block scope variables initialization 	
		int divisor	 = 0; // divisor = 10^i, i=0,1,2,...
		int quotient = 0; // quotient after integer divison
		int reminder = 0; // reminder after inter divison
		for ( int i = (maxDigits-1); i >= 0; --i ) 
		{
			divisor  = pow( 10, i );
			quotient = number / divisor;
			reminder = number % divisor; 
			// Display only digits of a number and separate with two spaces
			if ( number > divisor )
				cout << quotient << "  ";

			number = reminder; // new number is reminder
		}
	}//destroy scope variables

	cout << endl; // new line
}
