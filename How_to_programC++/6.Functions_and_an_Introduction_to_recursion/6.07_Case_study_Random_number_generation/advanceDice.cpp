// advanceDice.cpp
// Simulate rolling six-sided die 6 000 000 times
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using std::rand; // cstdlib
using std::srand;
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip
using std::time; // ctime

int main()
{
	// initialize values for each side
	int freq1 = 0; // count of 1s rolled
	int freq2 = 0; // count of 2s rolled
	int freq3 = 0; // count of 3s rolled
	int freq4 = 0; // count of 4s rolled
	int freq5 = 0; // count of 5s rolled
	int freq6 = 0; // count of 6s rolled

	srand( time(NULL) ); // generate every second different seed

	// Simulate rolling die; calculate frequencies occurance
	// of each side
	for (int i = 1; i <= 60000; ++i) {
		// get current face 
		int face = rand()%6 + 1; // random number from 1 to 6

		// determine roll value and increment appropriate counter
		switch (face) {
			case 1: freq1++; break;
			case 2: freq2++; break;
			case 3: freq3++; break;
			case 4: freq4++; break;
			case 5: freq5++; break;
			case 6: freq6++; break;
			default:
				cout << "Program should never get here!" << endl;
				break;
		}
	}

	// Display frequencies of each side
	cout << setw(5) << "Face"	<< setw(13) << "Frequency\n"
		<< setw(5) << "1"		<< setw(13) << freq1 << "\n"
		<< setw(5) << "2"		<< setw(13) << freq2 << "\n"
		<< setw(5) << "3"		<< setw(13) << freq3 << "\n"
		<< setw(5) << "4"		<< setw(13) << freq4 << "\n"
		<< setw(5) << "5"		<< setw(13) << freq5 << "\n"
		<< setw(5) << "6"		<< setw(13) << freq6 << endl;

	return 0;
}
