// main.cpp
// Read a number from input and round to the nearest integer,
// to the nearest tenth, to the nearest hundredth and to the nearest thousandth.
#include <iostream>
#include <iomanip>
#include <cmath>
#include "roundFunctions.h" // include header for functions that rounds numbers

int main()
{
	using namespace std;

	double number; // some floating-point number
	cout << "Enter floating-point number (-1 to exit): ";		
	cin >> number;

	// Display message for every non -1.0 floating point number
	// To properly exit loop some terminate condition must be taken
	// for floating-point number
	while ( fabs( number + 1.0 ) > 1e-5 ) 
	{
		// Display rounded number to different decimal places
		cout << number << setw(7) << roundToInteger( number ) 
			<< setw(7) << roundToTenths( number ) 
			<< setw(7) << roundToHundredths( number )
			<< setw(7) << roundToThousandths( number ) << endl;
		
		// Prompt message to user
		cout << "Enter floating-point number (-1 to exit): ";		
		cin >> number;
	}

	return 0;	
}
