// mainByValue.cpp
// Function pass by value.
#include <iostream>
using std::cout;
using std::endl;

// Print pasted value before and after local value modification
void foo( int y ) { 
	cout << "y = " << y << endl;

	y = -5645; // change y local value

	cout << "y = " << y << endl;
}// destroy y 

int main()
{
	int x = 6;	// create variable x
	
	cout << "x = " << x << endl;

	foo(x); // change local scope of x copy value

	cout << "x = " << x << endl;

	return 0;
}
