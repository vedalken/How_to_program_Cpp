// main.cpp
// 
// The Sieve of Eratosthenes - finding prime number.
// Initialize array to 1 and each multiple of the current
// element subscripts is set to 0. At the end, there 
// remains only prime numbers.
//
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip

void setPrimes( bool [], const int );
void setMultiples( bool [], const int, const int subscript );
void displayPrimes( bool [], const int );

int main()
{
	int arraySize = 10000;
	bool arrayPrimes[ arraySize ];

	// initialize array to 1, assuming all element
	// subscripts are prime numbers
	for ( int index = 0; index < arraySize; ++index )
		arrayPrimes[ index ] = true;
	
	// sets non primes to 0
	setPrimes( arrayPrimes, arraySize );

	// display only primes, set as elements to value 1
	displayPrimes( arrayPrimes, arraySize );

	return 0;
}// end main

//
// set non prime numbers to 0
// Loop over element, except element 0 and element 1
// (element 0 do not count, element 1 is by default prime!)
// Each element set to 1 and all multiples, but not its self, 
// are set to 0. At the end prime numbers only remains i.e.
// element values set to 1.
void setPrimes( bool array[], const int arraySize )
{
	// skip element 0 and element 1 (count starts with 2)!
	for ( int index = 2; index < arraySize; ++index )
	{
		// set multiples of index array values to 0
		if ( array[ index ] ) 
			setMultiples( array, arraySize, index );	
	}
}

// all multiples of "subscript" are set to 0, start counting
// forward "subscript+1"
void setMultiples( bool array[], const int arraySize, const int subscript )
{
	// multiple of subscript number
	int reminder = -1;

	for ( int index = subscript+1; index < arraySize; ++index ) 
	{
		reminder = index % subscript;
		// multiple number subscript is set to 0
		if ( reminder == 0 )
			array[ index ] = false;
	}
}

// print only elements set to 1-these are primes
void displayPrimes( bool array[], const int arraySize )
{
	int count = 0; // count primes
	// element 1 is trivial prime
	for ( int index = 1; index < arraySize; ++index )
	{
		if ( array[ index ] ) 
		{
			++count;
			cout << setw(7) << index;
			// every 10 columns print new line
			if ( count % 10 == 0 )
				cout << "\n";

		}
	}
	cout << "\n";
}
