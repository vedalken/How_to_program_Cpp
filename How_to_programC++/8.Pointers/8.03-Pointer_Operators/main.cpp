// main.cpp
// Pointer operator * and &.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int a; // a is integer
	int *aPtr; // aPtr is an int * which is pointer to integer
	
	a = 7; // assign 7 to a
	aPtr = &a; // assign address of a to aPtr

	cout << "Address of a: " << &a
		<< "\nthe value of aPtr: " << aPtr;
	cout << "\n\nValue of a: " << a
		<< "\nthe value of *aPtr: " << *aPtr;
	cout << "\n\nShowing that * and & are inverse of "
		<< "each other."
		<< "\n*&aPtr: " << *&aPtr
		<< "\n&*aPtr: " << &*aPtr << endl;

	return 0;
}
