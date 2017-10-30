// main.cpp
// Simulate coin tossig 100 times, and display 
// number of each side of the coin appears.
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout; // iostream
using std::endl;
using std::rand; // cstdlib
using std::srand;
using std::time; // ctime

// Flip tail = 0 or head = 1
bool inline flip() {
	return (rand() % 2);
}

int main()
{
	srand( time(NULL) ); // initialize seed with time
	
	// Count number of tails and heads of the coin side
	int tailCount = 0;
	int headCount = 0;

	for (int i = 0; i < 100; ++i)
	{
		if ( flip() ) { // coin side head
			++headCount;
		}
		else { // coin side tail
			++tailCount;
		}
	}

	// Display number of tails and heads count
	cout << "Tails: " << tailCount << endl;
	cout << "Heads: " << headCount << endl;

	return 0;	
}
