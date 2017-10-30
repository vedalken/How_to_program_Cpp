#include <iostream>

int main()
{ // outer block
	using namespace std;

	int nValue = 5;
	cout << nValue << endl;

	if (nValue >= 5)
	{ // nested block
		// hides the outer variable
		int nValue = 10;	
		// use the same name as outer variable
		cout << nValue << endl;
	} // nested nValue destroyed

	cout << nValue << endl;

	return 0;
} // outer nValue destroyed
