// initializerList.cpp
// Initialize array with initializer list.
#include <iostream>
#include <iomanip>
using std::cout;// iostream
using std::endl;
using std::setw;// iomanip

int main()
{
	// initialize array with initializer list
	// Compiler sizes array to size to number list elements
	int n[] = {13, 432, 45, 94, 52, 86, 9901, 1, 135, -153};

	cout << setw(7) << "Element" << setw(10) << "Value" << endl;

	// display array's elements and it's values
	for (int i=0; i < 10; ++i)
		cout << setw(7) << i << setw(10) << n[i] << endl;

	return 0;	
}
