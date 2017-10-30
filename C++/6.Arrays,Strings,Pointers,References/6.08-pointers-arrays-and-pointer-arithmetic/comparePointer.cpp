// comparePointer.cpp
// Compare two pointers in an array.
// Note: compile with -std=c++11 beacause of nullptr!
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	const int arraySize = 3;
	int array[ arraySize ] = { 10, 20, 30 };
	int* nPtr = array; // pointer to first element

	for ( int i = 0; nPtr <= &array[ arraySize-1 ]; ++i, ++nPtr )
	{
		cout << "Address of array[" << i << "] = " << nPtr
			<< "\nvalue of array[" << i << "] = " << *nPtr << endl;
	}
	nPtr = nullptr;
	return 0;	
}
