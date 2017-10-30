// main.cc 
// Display Celsius in Fahrenheit scale and vice versa.
#include <iostream>
#include <iomanip>
#include "functions.h"
using std::cout; //iostream
using std::endl;
using std::setw; //iomanip

int main()
{
	int celsiusMinTemp = 0; 	// minimal Celsius temperature
	int celsiusMaxTemp = 100;	// maximal Celsius temperature
	
	cout << setw(3) <<   "C" << setw(7)	<<     "F" << setw(7) << 	  "C" << endl;
	cout << setw(3) << "---" << setw(7)	<< "-----" << setw(7) << "-----" << endl;
	
	// Table with Celsius temperature, Fahrenheit conversion Celsius temperature, and
	// Celsius conversion Fahrenheit temperature
	for (int i = celsiusMinTemp; i <= celsiusMaxTemp; ++i) 
	{ 
		int fahTemp = fahrenheit( i ); // fahrenheit temperature
		cout << setw(3) << i << setw(7) << fahTemp << setw(7) << celsius( fahTemp ) << endl;
	}

	return 0;
}
