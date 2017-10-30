// main.cpp
// Program calculate square of integer. It's for demonstrating
// how function stack call works.
#include <iostream>
using std::cout;
using std::endl;
// Function prototype with function return type, that allocate memory
// for return (stack) variable address
int square( int ); 

// int address is push on stack i.e. stack frame (activation record)
// Main function returns 0 value to operating system, that program
// ended execution.
int main()
{
	// Declare automatic(local) variable in main function
	// Variable is also stored in function stack frame
	int a = 10; 

	// Square function is called and pushed on stack (new stack frame)
	// with stored return address of function square
	// After return is called, control is back to caller (i.e. main)
	cout << a << " square: " << square(a) << endl;

	// Return address is returned to operating system and control is back
	// to operating system
	return 0;
}

// Returns square of an integer
int square( int x ) // x is local variable
{	
	return x * x; // calculate square and return result
}// destroy automatic(local) variable
