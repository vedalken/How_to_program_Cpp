// main.cpp
// Table numbers from 1 to 1000, and prints all perfect numbers.
// Perfect numbers are those, which contains integers from 1 to n,
// where sum of all those equal to the perfect number.
#include <iostream>
using namespace std;

bool isPerfect( int ); // determine if number is perfect or not

int main()
{
	// Display perfect numbers from 1 to 1000.
	cout << "Perfect numbers are: " << endl;

	for (int i = 1; i <= 1000; ++i)
	{
		// Print perfect numbers
		if ( isPerfect(i) )
			cout << i << endl;
	}

	cout << endl;

	return 0;
}

// Function calculates if number is perfect number i.e.
// 6 = 1 + 2 + 3, is perfect number.
bool isPerfect( int number )
{
	int sum = 0; // sum of integers
	for (int i = 1; sum <= number; ++i)
	{
		sum += i;
		// Check if current sum equals input argument i.e.
		// than this is perfect number
		if ( sum == number )
			return true;
	}

	// non-perfect number
	return false; 
}
