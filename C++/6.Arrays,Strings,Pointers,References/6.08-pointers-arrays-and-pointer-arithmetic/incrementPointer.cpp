// incrementPointer.cpp
#include <iostream>
using namespace std;
int main()
{
	const int size = 3;
	int array[ size ] = { 10, 20, 30 };
	int* ptr = array; // point to first element in array
	
	for ( int i = 0; i < size; ++i )
	{
		cout << "address of array[" << i << "] = " << ptr;
		cout << "\nvalue of array[" << i << "] = " << *ptr << endl;
		++ptr; // point to next integer in array
	}
	return 0;	
}
