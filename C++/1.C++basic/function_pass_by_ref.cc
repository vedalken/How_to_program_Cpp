#include <iostream>
using namespace std;

void duplicate( int& a, int& b, int& c );

int main ()
{
	int x=1, y=4, z=6;
	cout << x << ", " << y << ", " << z << endl;
	
	// Multiply by 2 every parameter.
	duplicate(x, y, z);
	cout << x << ", " << y << ", " << z << endl;

	return 0;
}

// Multiplication by 2 every argument.
void duplicate( int& a, int& b, int& c )
{
	a *= 2;
	b *= 2;
	c *= 2;
}
