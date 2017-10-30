// Program calls add function with two parameters
// These parameter are added and return by caller.
#include <iostream>

// Declaration of add function
// add takes two integers as parameters, and returns the
// result of their sum 
// add does not care what are the exact values of x and y
int add(int x, int y)
{
	return x + y;
}

// Declaring main function
int main()
{
	using namespace std;
	
	// It is caller  of add() that decides the exact values of x and y
	cout << add(4, 5) << endl;

	return 0;
}
