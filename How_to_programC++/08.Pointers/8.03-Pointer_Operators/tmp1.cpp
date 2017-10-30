// tmp1.cpp
// Testing pointer operators.
#include <iostream>
using std::cout; // iostream
using std::endl;

int main()
{
	int firstValue, secondValue;
	int * ptr = nullptr;

	cout << "ptr: " << ptr << endl;
	ptr = &firstValue; // copy address of first variable
	*ptr = 10; // set variable value indirectly
	cout << "ptr: " << ptr << endl;
	ptr = &secondValue; // copy address of second variable
	*ptr = 20; // set second variable value, indirectly
	cout << "ptr: " << ptr << endl;

	cout << "\nfirst variable: " << firstValue
		<< "\nits address: " << &firstValue
		<< "\nsecond variable: " << secondValue
		<< "\nits address: " << &secondValue << endl;

	return 0;
}
