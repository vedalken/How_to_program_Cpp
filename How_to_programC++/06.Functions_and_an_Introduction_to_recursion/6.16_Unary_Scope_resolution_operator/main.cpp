// main.cpp
// Call global variable with unary scope resolution operator i.e. "::".
// Use :: on global variables for any ambiguities - even though name 
// of local scope variable is different from one declared as global.
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::left;

int number = 5; // some global variable initialization

int main()
{
	// Display global variable address
	cout << left << setw(30) << "global variable address " << setw(15) << &number << endl;

	// Declare local variable; compiler hides global variable
	int number = 0;
	
	// Display local and global variable (and address in memory)
	cout << setw(30) << "local variable " << number << ", " << setw(15) << &number << endl;
	cout << setw(30) << "global variable " << ::number << ", " << setw(15) << &::number << endl;
	return 0;
}
