// main.cpp
// Determine the largest number, char, floating point
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// determine the largest number
template <typename T> 
T maximum( T par1, T par2 )
{
	T max;
	max = par1; // assume par1 is the largest

	// check if par2 is maybe the largest 
	if( par2 > max )
		max = par2;

	return max;
}

int main()
{
	cout << "Enter two numbers: ";
	float val1;
	float val2;
	cin >> val1 >> val2;

	// display the smallest number
	cout << "Maximum is " << maximum(val1, val2) << endl;

	return 0;
}

