// mainByValue.cpp
// Function pass by value.
#include <iostream>
using std::cout;
using std::endl;

// Print pasted value
void foo( int y ) { // create y 
	cout << "y = " << y << endl;	
}// destroy y 

int main()
{
	foo(5); // pass by literal value

	int x = 6;	// create variable x
	foo(x);		// pass variable x to function; copy x value to y
	foo(x+1); 	

	return 0;
}
