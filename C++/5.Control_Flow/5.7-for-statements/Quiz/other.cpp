// other.cpp
// Program prints every other number from 2 to 20.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// Display every other number
	for (int i=2; i<=20; i+=2) {
		cout << i << " ";
	}

	cout << endl; // new line

	return 0;
}
