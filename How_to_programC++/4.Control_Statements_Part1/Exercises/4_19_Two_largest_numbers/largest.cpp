// twoLargest.cpp
// Program determines two largest numbers.
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
	int secondLargest;		// second largest number
	int largest	= number;	// current largest number	
	int counter = 1;	 	// count input
	
	// From 10 inputs determine largest number
	while (counter < 10)
	{
		cout << "Enter number: ";
		cin >> number;
		
		// Determine largest number
		if (number > largest) 
		{
			secondLargest	= largest;	// second largest in previous largest
			largest			= number;	// current largest number
		}
		
		// Increment counter
		++counter;
	}

	// Display largest and second largest number
	cout << "Largest is " << largest
		<< "\nSecond largest is " << secondLargest << endl;

	return 0;	
}
