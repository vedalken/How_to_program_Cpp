// main.cpp
// Determine desired integer power of a integer number.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int number;
	int powerNumber;

	// Display message for input
	cout << "Enter integer number and integer power: ";
	cin >> number >> powerNumber; // read input

	int power	= 1; // power of the number
	int i		= 1; // counter for power

	// compute power of a number i.e. number^(powerNumber)
	while (i <= powerNumber)
	{
		power *= number;
		++i;
	}
	
	// for power number equals 0, power of number is 1!
	if (powerNumber == 0) {
		power = 1;
	}

	cout << "Power " << powerNumber << " of " << number
		<< " is " << power << endl;

	return 0; 
}
