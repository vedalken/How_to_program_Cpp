// main.cpp
// Write C++ statements.
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::fixed;
using std::setprecision; // iomanip

int main()
{
	const int nArraySize = 10; // define array size
	double anFractions[ nArraySize ] = {}; // initialize array to 0
	
	//anFraction[ 3 ]; // 4th element 
	anFractions[ 3 ] = anFractions[ 4 ]; // assign element 4 to element 3
	anFractions[ 9 ] = 1.667; // element 9
	anFractions[ 6 ] = 3.333; // 7th element
	
	// display element 6 and 9 with two decimal digits
	cout << "anFractions[ 6 ] = " 
		<< fixed << setprecision( 2 ) << anFractions[ 6 ] << endl
		<< "anFractions[ 9 ] = " << anFractions[ 9 ] << endl;
	
	// print array
	cout << "\nDisplay array" << endl;
	for ( int i = 0; i < nArraySize; ++i )
		cout << "anFractions[ " << i << " ] = " << anFractions[ i ] << endl;

	return 0;
}//end main
