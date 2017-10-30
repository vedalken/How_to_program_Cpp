#include <cmath>
#include "roundFunctions.h" // function declaration

// Round floating-point number to first integer
int roundToInteger( double number ) 
{
	using std::floor;

	// Add 0.5 to number to round down if decimal number <= 0.5
	// and round up if decimal number is > 0.5
	return floor( number + .5 ); 
}

// Round floating-point number to the nearest tenth
double roundToTenths( double number ) 
{
	using std::floor;

	double rounded; // rounded number
	rounded = floor( number * 10 + .5 ) / 10; // round to the nearest tenth
	return rounded;
}

// Round floating-point number to the nearest hundredth
double roundToHundredths( double number )
{
	using std::floor;

	double rounded; // rounded number
	rounded = floor( number * 100 + .5 ) / 100; //round to the nearest hundredth
	return rounded;
}

// Round floating-point number to the nearest thousandth
double roundToThousandths( double number )
{
	using std::floor;

	double rounded; //rounded number
	rounded = floor( number * 1000 + .5 ) / 1000; //round to the nearest thousandths
	return rounded;
}
