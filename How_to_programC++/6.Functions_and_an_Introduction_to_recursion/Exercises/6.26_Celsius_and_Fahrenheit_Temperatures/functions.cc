// functions.cc
#include <cmath>
#include "functions.h"
using std::floor;

// Convert Fahrenheit temperature into Celsius
int celsius( int fahrenheitTemp )
{
	double fahToCels;
	// convertions from Fahrenheit scale to Celsius
	fahToCels = (5.0 / 9.0) * ( fahrenheitTemp - 32 );
	
	int nCelsius;
	// round up celsius degrees to integer
	nCelsius = floor( fahToCels + 0.5 );
	
	return nCelsius;
}

// Convert Celsius temperature into Fahrenheit
int fahrenheit( int celsiusTemp ) 
{
	// convert from Celsius to Fahrenheit temp scale
	double celsToFah;
	celsToFah = (9.0 / 5.0) * celsiusTemp + 32;

	// round up fahrenheit degrees to integer
	int nFahrenheit; 
	nFahrenheit = floor( celsToFah + 0.5 );

	return nFahrenheit;
}
