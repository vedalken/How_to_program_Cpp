// simpleDice.cpp
// Simulate toss 6-sided dice 20 times with random generator.
// Display each value in saparate field.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip
using std::setprecision;
using std::fixed;
using std::rand; // cstdlib
using std::srand;
using std::clock; // ctime

int main() 
{
	clock_t ticks;
	const int nToss 	= 20;	// number of tossed dice
	const int nSideDice = 6; 	// 6 sided dice
	
	cout << "RAND_MAX " << RAND_MAX << endl;
	
	ticks = clock();
	
	for (unsigned i=1; i<1000000; ++i);
	// Initialize random generator with different seeds
	// Seed is determined every second 
	srand( time(NULL) ); 

	cout << "The number of elapsed seconds since Jan 1, 1970 is " << time(NULL) << endl;
	// srand(1); // every runtime program will generate same result

	// Simulate toss 6-sided dice 20 times
	// Separate field view 
	for (int i = 1; i <= nToss; i++) {
		// random generate numbers in range from 0 to 5 (print values: 1-6)
		cout << setw(5) << ( rand() % nSideDice + 1 ); 
		
		if (i % 5 == 0) 
			cout << endl; // display new line
	}

	ticks = clock() - ticks;

	cout << fixed << setprecision(4) << static_cast<float>(ticks)/CLOCKS_PER_SEC << endl;

	return 0; //success	
}
