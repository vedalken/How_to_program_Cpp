// main.cpp
// Determine the smallest number, char, floating point
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// determine smallest number
template <typename T> 
T minimum( T par1, T par2 )
{
	T min;
	min = par1; // assume par1 is the smallest

	// check if par2 is maybe smallest
	if( par2 < min )
		min = par2;

	return min;
}

int main()
{
	cout << "Enter two numbers: ";
	int val1;
	int val2;
	cin >> val1 >> val2;

	// display the smallest number
	cout << minimum(val1, val2) << endl;

	return 0;
}

