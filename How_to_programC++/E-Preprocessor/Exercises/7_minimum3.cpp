//  MINUMUM2 determines the smaller of 
//  two number values
//  Read input values. 
#include <iostream>
#define MINIMUM2( x, y ) ((x<y)?x:y) 
#define MINIMUM3( x, y, z ) ((z<MINIMUM2(x,y))? z : MINIMUM2(x,y))

double inline minimum2( double x, double y ) { return (x<y?x:y); }
double inline minimum3( double x, double y, double z ) 
{
	double min2 = minimum2( x, y );
	return ( z < min2 ) ? z:min2;	
}

using namespace std;

int main()
{
	double value1;
	double value2;
	double value3;

	cout << "Enter first value:";
	cin >> value1;
	cout << "Enter second value:";
	cin >> value2;
	cout << "Enter third value:";
	cin >> value3;

	cout << "Smaller of the entered values is: " 
		<< MINIMUM3( value1, value2, value3 ) << endl;
	
	double min3 = minimum3( value1, value2, value3 );
	cout << "inline function call.\nSmaller of the entered values is: " 
		<< min3 << endl;
	
	return 0;	
}
