#include <iostream>

int main()
{
	using namespace std;
	unsigned short x = 65535;	// larges 2-byte unsigned value
	cout << "x was: " << x << endl;
	
	unsigned short y;
	y = x + 1;	// we desire 65536, but we get overflow!
	cout << "y is now: " << y << endl;
	
	x = x + 2;
	cout << "x is now: " << x << endl;

	return 0;
}
