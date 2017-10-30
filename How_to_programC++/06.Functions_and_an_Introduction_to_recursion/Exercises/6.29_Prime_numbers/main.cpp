// main.cpp
// Calculate prime numbers.
// Display prime numbers from 2 to 1000
#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout; //iostream
using std::endl;
using std::setw; // iomanip
using std::ceil; // cmath
using std::sqrt;

bool isPrime( int ); // function prototype

int main()
{
	// Display prime numbers
	for ( int i = 2, j = 0; i <= 50000; ++i )
	{
		if ( isPrime(i) ) {
			cout << setw(6) << i;
			j++;
			
			if ( j % 20 == 0 )
				cout << "\n"; // newline
		}
	}

	cout << endl; // new line
	
	return 0;
}

// Function calculates if number is prime.
bool isPrime( int number )
{
	// Calculate reminder after division
	// Trivial reminder after division by 1 and by its self
	// is ommited.
	// If reminder is 0, than number is not prime, otherwise
	// number is prime.
	for (int i = 2; i <= ceil( sqrt(number) ); ++i)
	{
		if ( i == number )
			continue;
		if ( i < number )
		{
			if ( ! (number % i) ) 	// check zero reminder
				return false; 		// number is not prime
		}
		else { // ommite calculation with greater number than its self
			break; 
		}
	}

	return true; // number is prime
}// end function isPrime
