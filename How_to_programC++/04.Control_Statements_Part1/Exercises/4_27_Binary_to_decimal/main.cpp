// main.cpp
// Convert binary to decimal.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// Function prototype
long long power( int number, int pow );

// Program execution
int main()
{
	long long binary; // input binary number
	
	cout << "Enter binary value: ";
	cin >> binary;

	// Maximum binary number is 1 byte = 8 bits
	long long binaryValue	= power(2,7); // most significant bit
	long long decimalValue 	= 1e7;
	
	int digit;			// digit of binary number
	int decimal = 0; 	// decimal value converted from binary number

	while (binaryValue >= 1) // read all binary digits
	{
		digit = binary / decimalValue; 	// binary digit
		binary %= decimalValue; 		// reminder after division is new value
		decimal += digit * binaryValue;	// convert binary number to decimal
		binaryValue /= 2;				// go to next bit, with new value (binary)
		decimalValue /= 10;		
	}

	// Display message of converted binary to decimal
	// and print decimal value.
	cout << "\nConverted binary to decimal is: " << decimal << endl;

	return 0;
}

// Compute number's with power pow i.e. 2^7 (pow = 7, number = 2)
long long power(int number, int pow)
{
	int counter	= 1;
	int tmpPower = 1; // temporary power of number 

	// Compute power of number
	while (counter <= pow)
	{
		tmpPower *= number;
		++counter;
	}

	return tmpPower;
}
