// largest.cpp
// Program determines largets price sold for ten salesperons.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int number;

	// Read input number by user
	cout << "Enter number: ";
	cin >> number;

	// Declare and initialize variables
	int largest = number;	// current largest number	
	int counter = 1;	 	// count input
	
	// From 10 inputs determine largest number
	while (counter < 10)
	{
		cout << "Enter number: ";
		cin >> number;
		
		// Determine largest number
		if (number > largest) 
		{
			largest = number; // current largest number
		}
		
		// Increment counter
		++counter;
	}

	// Display largest number
	cout << "Largest is " << largest << endl;

	return 0;	
}
