// prng.cpp or pseudo-random number generator (prng)
// Generates some pseudo-random numbers.
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip

// function generates random number
unsigned pseudoRNG() {
	static unsigned seed = 5493; // some (any) initial starting seed; initialized only once!

	// Take the current seed and generate new value from it
	// Due to larg numbers used to generate numbers is difficult to
	// predict next value from previous one.
	// Static keyword has program scope and is terminated at the end of
	// program. Seed value is stored every time in memory using previous 
	// value.
	seed = (3852591 * seed + 5180347);

	// return value between 0 and 65535
	return (seed % 65535);
}

int main()
{
	// generate 100 random numbers - print in separate fields
	for (int i = 1; i <= 100; i++) {
		cout << setw(8) << pseudoRNG();

		// new line every fifth number
		if (i % 5 == 0)
			cout << endl;
	}

	return 0;
}
