// duplicate.cpp
// Duplicate numbers by calling function duple passing by value by reference.
#include <iostream>
using namespace std;

// Function that duplicates number
void duple( int &a, int &b, int &c ) {
	a *= 2;
	b *= 2;
	c *= 2;
}

int main()
{
	// declare and initialize three variables
	int x = 2;
	int y = 5;
	int z = 12;
	
	cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
	duple(x,y,z); // duplicate each number
	cout << "x=" << x << ", y=" << y << ", z=" << z << endl;

	return 0;	
}
