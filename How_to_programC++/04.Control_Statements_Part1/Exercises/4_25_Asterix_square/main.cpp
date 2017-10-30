// main.cpp
// Program displays asterix hole square.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int number;
	cout << "Enter a number: "; // prompt message to user
	cin >> number;				// read number

	int i = 1; // number of asterixes
	
	// Display line with n asterix
	while (i <= number ) {
		cout << "* ";
		++i;
	}

	cout << endl; // new line

	// Display empty square
	while (i <= number*(number-1) )
	{
		if ((i-1) % number == 0) // left side of a square
		{
			cout << "* ";
		}
		else if (i % number == 0) // right side of a square, and new line
		{ 
			cout << "* " << endl; 
		}
		else 
		{
			cout << "  "; // empty square, no asterix
		}
	
		// increment i
		++i;
	}
	
	// Bottom of empty square
	while (i <= number*number ) {
		cout << "* ";
		++i;
	}

	cout << endl; // new line

	return 0;	
}// end main function
