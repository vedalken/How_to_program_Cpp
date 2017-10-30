// minNoInline.cpp
// Inline function call min, which returns minimum value.
#include <iostream>

// calculate mininimum value with inline function 
inline int min( int x, int y) {
	return (x>y ? y : x);
}

int main() 
{
	using namespace std;
	cout << min(5,6)	<< endl;
	cout << min(4,-1)	<< endl;

	return 0;
}
