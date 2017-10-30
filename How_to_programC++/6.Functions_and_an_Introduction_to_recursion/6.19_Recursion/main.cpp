// main.cpp
// Calculate factorial of integer numbers from 1 to 10.
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip

unsigned long factorial( unsigned long ); // function prototype

int main() 
{	
	// Display factorials of integer 0 to 10
	// counter is implicitly converted to type unsigned long
	for ( int counter = 0; counter <= 10; ++counter ) 
		cout << setw(2) << counter << "! = " << factorial( counter ) << endl;
	
	return 0;	
}

// Recursive definition of function factorial
unsigned long factorial( unsigned long number ) 
{
	if (number > 1) // non-base case; recursion step!
		return number * factorial( number - 1 );
	else
		return 1; // 0! = 1 and 1! = 1
}
