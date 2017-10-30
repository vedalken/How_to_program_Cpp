//  MINUMUM2 determines the smaller of 
//  two number values
//  Read input values. 
#include <iostream>
#define MINIMUM2( x, y ) ((x<y)?x:y) 

double inline minimum2( double x, double y ) { return ( x<y ? x:y ); }

using namespace std;

int main()
{
	double value1;
	double value2;

	cout << "Enter first value:";
	cin >> value1;
	cout << "Enter second value:";
	cin >> value2;

	cout << "Smaller entered value is " 
		<< MINIMUM2( value1, value2 ) << endl;
	
	double min = minimum2( value1, value2 );
	cout << "inline function.\n"
		"Smaller entered value is " << min << endl;

	return 0;	
}
