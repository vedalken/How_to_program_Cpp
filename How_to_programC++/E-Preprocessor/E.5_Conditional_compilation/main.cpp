// main.cpp
// Condition compilation
// run gcc -E main.cpp > main.p for processor procedure
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#define MIN(x,y) ( ((x)<(y)) ? x : y) // macro defined function

#define DEBUG // debug program; remove and no debugging will occur

int main()
{
	int i = 100;
	int j = 200;
	
#ifdef DEBUG
	cerr << "Trace: Inside main function." << endl;
#endif

// don't compile in if statement!
#if 0 
	cout << blala(C++) << endl;
#endif

	// print minimum value 
	cout << "Minimum is " << MIN(i,j) << endl;

#ifdef DEBUG
	cerr << "Trace: Coming out of main function." << endl;
#endif

	return 0;	
}
