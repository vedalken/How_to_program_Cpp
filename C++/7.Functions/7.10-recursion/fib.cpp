// fib.cpp
// Calculate fibonacci's numbers
#include <iostream>
using namespace std;

unsigned long fibonacci( unsigned long );

// Main program
int main() 
{
	// Display first 12 Fibonacci numbers
	for (int iii=0; iii < 13; ++iii)
		cout << fibonacci( iii ) << endl;

	return 0;
}

// Recursively calculate Fibonacci's numbers
unsigned long fibonacci( unsigned long number )
{
	if (number == 0 || number == 1)
		return number;
	else // resursive call
		return fibonacci( number-1 ) + fibonacci( number-2 );
}
