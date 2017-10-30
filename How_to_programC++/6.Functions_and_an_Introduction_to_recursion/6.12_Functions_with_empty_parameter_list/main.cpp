// main.cpp
// Program calls two different functions with different parameter specifier
// that does not return anything.
#include <iostream>
using namespace std;

void function1(); 		// function prototype with empty parameter list
void function2( void ); // function prototype with empty parameter list-using void

int main()
{
	function1(); // function1 and function2 call
	function2();

	return 0;
}

// function1 takes empty parameter list (receives no arguments)
void function1() {
	cout << "function1 takes no arguments." << endl;	
}

// function2 uses a void parameter list to specifiy that the function receives 
// no arguments
void function2( void ) {
	cout << "function2 also takes no arguments" << endl;
}
