// c.cpp
// Calculate 2.5^3 with precision 2 in a field width 10.
#include <iostream>	// call: cout, endl
#include <cmath> 	// function call: pow
#include <iomanip>	// function call: setprecision, setw

// Program execution begins with main
int main()
{
	// Compute 2.5 with power 3 in precision with 2 decimals and displayed
	// in a field width of 10 characters
	std::cout << std::fixed << std::setprecision(2) << std::setw(10)
			<< std::pow( 2.5, 3 ) << std::endl;

	return 0;
}
