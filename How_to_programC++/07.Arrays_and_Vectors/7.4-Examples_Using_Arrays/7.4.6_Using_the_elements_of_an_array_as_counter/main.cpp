// main.cpp
// Roll die 6.000.000 times.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::srand; // cstdlib
using std::rand;
using std::time; // ctime
using std::setw; // iomanip

int main()
{
	const int arraySize = 7;  	// ignore element zero (with index zero)
	int frequency[arraySize] = {};	// initialize elements to 0

	srand( time(0) ); 			// seed random number generator

	// roll die 6.000.000 times; use array index as frequency index
	for (int i = 0; i < 6000000; ++i)
		++frequency[ 1+rand()%6 ];

	cout << setw(4) << "Face" << setw(15) << "Frequency" << endl;
	
	// display die frequency with array elements
	for (int i = 1; i < arraySize; ++i)
		cout << setw(4) << i << setw(15) << frequency[i] << endl;

	return 0;	
}
