// Program uses SUMARRAY macro to sum values of an array.
// Macro receive the array and the number of elements in 
// the array as arguments
#include <iostream>
#include "macrosdef.h"

using namespace std;

int main()
{
	double a[10] = {1,2,3,4,5,6,7,8,9,10}; 

	SUMARRAY(a, 10) // 55
	
	cout << "Inline function\n";
	sumArray( a, 10 );

	return 0;	
}
