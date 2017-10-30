// min.cpp
// Define macro to determine minimum value.
// min.p is preprocessor output; look last lines!
#include <iostream>
using std::cout;
using std::endl;

// define macro for determining smaller value
#define MIN(a,b) ( ((a)<(b)) ? a : b )

int main()
{
	int i = 100;
	int j = 200;

	// display smaller value
	// arguments are passed to macro replacement text; replacement expression is
	// replaced by preprocessor before compilation
	cout << "The minimum is " << MIN(i, j) << endl;

	return 0;	
}
