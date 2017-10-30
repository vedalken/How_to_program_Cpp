// minNoInline.cpp
// Function call min, which returns minimum value.
#include <iostream>
using std::cout;
using std::endl;

// calculate mininimum value
int min( int x, int y) {
	return (x>y ? y : x);
}

int main() 
{
	cout << min( 5, 6)	<< endl;
	cout << min( 4, -1) << endl;

	return 0;
}
