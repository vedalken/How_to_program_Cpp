// refNotInitialized.cpp
// Use alias to change original value.
#include <iostream>
using namespace std;

int main()
{
	int x = 3;
	int &y; // reference must be initialized

	cout << "x = "	<< x << endl;
	
	// change twice original value
	y = 7;

	cout << "x = "	<< x << endl;
	
	return 0;	
}
