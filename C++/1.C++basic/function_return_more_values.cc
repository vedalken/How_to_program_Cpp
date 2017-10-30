#include <iostream>
using namespace std;

void prevnext( int& x, int& prev, int& next );

int main ()
{
	int x = 100, y = 0, z = 0;

	cout << x << endl;
	
	// returns previous and next number of 
	// the first parameter passed
	prevnext( x, y, z );
	cout << "Previous: " << y << ", Next: " << z << endl;

	return 0;
}


void prevnext( int& x, int& prev, int& next )
{
	prev = x - 1;
	next = x + 1;
}
