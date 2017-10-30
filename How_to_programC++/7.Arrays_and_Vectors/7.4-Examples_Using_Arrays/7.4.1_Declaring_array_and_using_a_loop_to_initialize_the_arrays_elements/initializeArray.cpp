// initializeArray.cpp
// Initialize an array's elements to zero and print those values.
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip

int main()
{
	int n[10] = { }; // declare array; automatic arrays are not implicit initialized

	// initialize array's elements to zero
	//for (int i = 0; i < 10; ++i)
	//	n[i] = 0;

	cout << setw(7) << "Element" << setw(10) << "Value" << endl;
	
	// Display array's elements and their values
	for (int i = 0; i < 10; ++i)
		cout << setw(7) << i << setw(10) << n[i] << endl;

	return 0;	
}
