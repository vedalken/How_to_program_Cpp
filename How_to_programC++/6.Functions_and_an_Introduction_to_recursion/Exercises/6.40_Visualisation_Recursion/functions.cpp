// functions.cpp
// Implement recursive factorial calculation.
// Display recursive depth with indention.
#include <iostream>
#include <iomanip>
using std::cout;// iostream
using std::endl;
using std::setw;// iomanip

int factorial( int n )
{
	static int count = 0; 	// count number of function calls
	const int shift = 1;	// shift indention 
	++count;

	if (n <= 1) {
		cout << setw( count+shift ) << n << "! = " << "1" << endl;
		return 1;
	}
	else {
		cout << setw( count+shift ) << n << "! = " << n 
			 << "*factorial(" << n-1 << ")" << endl;
		
		int fac = factorial( n-1 );
		int result = n * fac;
		--count; 				// decrease counter for clearer alignment

		cout << setw( count+shift ) << n	 << "! = " << n 
			 << "*factorial(" << n-1 << ") = " << result << endl;

		return result;
	}
}
