// fib.cpp
// Calculate some of Fibonacci numbers.
// Display first ten Fibonacci's numbers, and 20th, 30th, 35th number.
#include <iostream>
using std::cout;
using std::endl;

unsigned long fibonacci( unsigned long ); // function prototype

int main()
{
	// Display first ten Fibonacci's numbers
	for (unsigned i=0; i<=10; ++i) 
		cout << "fibonacci( " << i << " ) = " << fibonacci( i ) << endl;

	// Print 20th, 30th and 35th Fibonacci number
	// If numbers are too big, stack overflow may occure!
	cout << "fibonacci( 20 ) = "	<< fibonacci( 20 ) << endl;
	cout << "fibonacci( 30 ) = "	<< fibonacci( 30 ) << endl;
	cout << "fibonacci( 40 ) = "	<< fibonacci( 40 ) << endl;

	return 0;
}

// Fibonacci number calculatation using recursion
// n=0, fib(0) = 0
// n=1, fib(1) = 1
// n>=2, fib(n) = fib(n - 1) + fib(n - 2)
unsigned long fibonacci( unsigned long number ) 
{
	if (number == 0 || number == 1) // base condition
		return number;
	else
		return fibonacci( number - 1 ) + fibonacci( number - 2 );
}
