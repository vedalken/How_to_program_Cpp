// functions.cpp
#include <iostream>
#include <cmath> // using: pow()
#include "functions.h"
using std::cout; // iostream header
using std::pow;	// cmath header
using std::endl;

// Convert small decimal number to 8 bits or 1 byte
void decimal2binary( int decimal )
{	
	int reminder; 	// reminder after division
	int power;
	int count = 0;

	do {
		power = static_cast<int>( pow(2, count++) );
	} while(decimal > power);
	
	bool digit; // digit after division
	
	for (int i = --count; i >= 0; --i) {
		power = static_cast<int>( pow(2,i) ); // power of 2; 2^i
		digit = decimal / power; 
		reminder = decimal % power;
		
		// if zero digit go to next digit
		if (digit == 0) {
			cout << digit; // print digit, decimal value is unchanged!
			continue;
		}
		else { 
			cout << digit;
		}

		decimal = reminder; // current decimal number
	}

	// Display new line
	cout << endl;
}

// Convert small decimal number to octal number
void decimal2octal( int decimal )
{
	int reminder;	// reminder after division
	int count = 0; // count number of nonzero digits
	int power;

	// Find most significant digit for start of decimal to octal conversion
	do {	
		power = static_cast<int>( pow(8, count++) );
		reminder = decimal % power;
	} while	(reminder != 0);
	
	int octalDigit; // from 0 to 7

	// Converting octal to decimal
	for (int i = count; i >= 0; --i) {	
		power = static_cast<int>( pow(8, i) );
		octalDigit = decimal / power;
		reminder = decimal % power;
		cout << octalDigit;

		if (octalDigit == 0) continue;

		decimal = reminder;
	}
	
	// new line
	cout << endl;
}

// Convert decimal number to hexadecimal 
void decimal2hexadecimal( int decimal )
{
	int power;
	int reminder;
	int count = -1; // start counter with -1
	do {
		power = static_cast<int>( pow(16, ++count) );
	} while(power <= decimal);
	
	// Hexadecimal digit
	int hexaDigit;

	for (int i = count; i >= 0; --i) 
	{
		power = static_cast<int>( pow(16, i) );
		hexaDigit = decimal / power;
		reminder = decimal % power;
		
		// Convert decimal to hexadecimal
		switch (hexaDigit) 
		{	// Numbering scheme
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9: cout << hexaDigit; 
					break;
			// Latter scheme
			case 10: cout << 'A'; break;
			case 11: cout << 'B'; break;
			case 12: cout << 'C'; break;
			case 13: cout << 'D'; break;
			case 14: cout << 'E'; break;
			case 15: cout << 'F'; break;
			
			default: ;
		}
		// Reminder is new decimal value 
		decimal = reminder;
	}
	cout << endl;
}




