// srand.cpp
// Generate numbers with different seeds every second.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
//using std::cout; // iostream
//using std::endl;
//using std::srand; // cstdlib
//using std::rand;
//using std::time; // ctime
//using std::setw; // iomanip

int main()
{
	std::srand( std::time(NULL) ); // seed random number generator

	for (int count = 1; count <= 20; ++count) {
		std::cout << std::setw(5) << (1 + std::rand()% 6);

		// Five numbers in one line
		if (count % 5 == 0)
			std::cout << std::endl;
	}

	return 0;
}
