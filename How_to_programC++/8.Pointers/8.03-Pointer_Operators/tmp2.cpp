// tmp2.cpp
// Testing some pointer operations.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int firstValue = 5, secondValue = 6;
	int* ptr1 = nullptr;
	int* ptr2 = nullptr;
	
	cout << "\nfirst value: " << firstValue
		<< "\nsecond value: " << secondValue << endl;

	ptr1 = &firstValue; // copy address of first variable
	ptr2 = &secondValue; // copy address of second variable
	*ptr1 = 10; // indirectly set new value to first variable
	*ptr2 = *ptr1; // set new value to second variable, indirectly
	ptr1 = ptr2; // copy address of second pointer into first
	// because address of second pointer is copied into
	// first pointer, meaning both pointing at same memory address,
	// both now pointing to same value
	*ptr1 = 25; // set new value to second variable
	
	cout << "\nfirst value: " << firstValue
		<< "\nsecond value: " << secondValue << endl;

	return 0;	
}
