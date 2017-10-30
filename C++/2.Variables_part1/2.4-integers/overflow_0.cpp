#include <iostream>

int main()
{
	using namespace std;
	// binary 0 is: 0000 0000 0000 0000
	unsigned short x = 0;	// smallest 2-byte unsigned value possible
	cout << "x was: " << x << endl;
	// we get, binary: 1111 1111 1111 1111
	x = x - 1;	// we expect -1, we get overflow!
	cout << "x is: " << x << endl;
	
	return 0;
}
