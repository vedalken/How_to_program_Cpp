// main.cpp
// Program calculate maximal heart rate, target heart rate, it's age 
// and other things.
#include "HeartRates.h"

int main()
{
	// initialize object
	HeartRates	person1("Milos", "Bajic", 1987);
	HeartRates	person2("Miha", "Praprotnik", 1953);
	
	// display person's health information
	person1.displayHealth();
	person2.displayHealth();

	return 0;
}// end main
