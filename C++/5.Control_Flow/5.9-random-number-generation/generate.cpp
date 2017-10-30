// generate.cpp
// Generate different sequence of random numbers every time
// program starts.
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout; // iostream
using std::endl;
using std::srand; // cstdlib
using std::rand;
using std::time; // ctime

int main()
{
	srand( time(NULL) ); // set initial seed value to system clock 	
	
	// generate 100 random numbers
	for (int i=1; i <= 100; ++i) {
		cout << ( 1 + rand()%10 ) << "\t";

		if (i % 5 == 0)
			cout << endl;
	}

	return 0;
}
