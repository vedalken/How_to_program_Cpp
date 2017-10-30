// calSeconds.cpp
// Calculate time in seconds since the last time struck 12 (12-hour cycle clock)
// and calculate time difference between two times, both are within one 
// 12-hour cycle of a clock.
#include <iostream>
using namespace std;

// 12-hour clock cycle!
// function returns time, in seconds, since the last time clock struck 12 
long timeInSeconds( int hours, int minutes, int seconds ); 

int main()
{
	long differ = 0;
	// Time difference 
	differ = timeInSeconds( 9, 15, 6 ) - timeInSeconds( 5, 55, 45 );
	cout << "Time difference: " << differ << endl;
	
	return 0;	
}

long timeInSeconds( int hours, int minutes, int seconds ) 
{
	// scaling factor, convert: min -> s, hours -> min
	long scaleFactor = 60; 

	// total time, converted in seconds
	long totalTimeInSeconds;
	totalTimeInSeconds = scaleFactor * scaleFactor * hours  + 
						 scaleFactor * minutes +
						 seconds;

	return totalTimeInSeconds;
}

