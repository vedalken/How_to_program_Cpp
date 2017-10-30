// castVoidPointer.cpp
// Void pointer cannot be dereferenced and 
// there is no reference. Compiler does not know
// what object is void pointer using int, or double,
// or class etc.
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	int value = 5;
	void* voidPtr = &value; // void pointer
	
	// cannot be dereferenced - compile error!
	cout << "voidPtr: " << voidPtr
		<< "\n&voidPtr: " << &voidPtr << endl; // allowed
	//cout << *voidPtr << endl; // not allowd
	
	// we know voidPtr point to integer and is up to us
	// to cast properly
	int* intPtr = static_cast<int* >( voidPtr );
	
	cout << "intPtr: " << intPtr
		<< "\n*intPtr: " << *intPtr << endl;
}
