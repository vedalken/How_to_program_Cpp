// alias.cpp
// Use alias to change original value.
#include <iostream>
using namespace std;

int main()
{
	int x = 3;
	int &y = x;

	cout << "x = "	<< x << "\n"
		<< "y = "	<< y << endl;
	
	// change twice original value
	x = 5;
	y = 7;

	cout << "x = "	<< x << "\n"
		<< "y = "	<< y << endl;
	
	return 0;	
}
