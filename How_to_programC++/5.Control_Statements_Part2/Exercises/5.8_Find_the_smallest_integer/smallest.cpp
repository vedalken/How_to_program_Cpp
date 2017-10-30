// smallest.cpp
// Find the smallest integer. First integer specifies 
// number of left integers to read.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	// Assume first read number speficies number
	// of integers to read
	int n; // number of integers to read
	cin >> n;

	int smallest; 	// the smallest number
	cin >> smallest; // first number is the smallest

	// Find the smallest integer
	for (int i = 1; i < n; ++i)
	{
		int number;
		cin >> number; // read integer
		// Test if number is the smaller then previous saved
		if (number < smallest) { 
			smallest = number; // current the smallest
		}
	}

	cout << "\nThe smallest: " << smallest << endl;

	return 0;
}
