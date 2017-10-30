// main.cpp
// Testing pointers by using offset.
#include <iostream>
int main()
{
	using namespace std;
	
	const int size = 4;
	int b[ size ] = { 10, 20, 30, 40 };
	int* bPtr = b; // pointer to first element == &b[0]

	// using array subscript notation
	cout << "Array b" << '\n'
		<< "\nArray subscript notation:\n";
	
	for (int i = 0; i < size; ++i)
		cout << "b[" << i << "] = " << b[i] << '\n';
	
	// pointer offset notation with the array name as pointer
	cout << "\nPointer/offset notation with array name as pointer:\n";
	
	for (int offset = 0; offset < size; ++offset)
		cout << "*(b + " << offset << ") = " << *(b + offset) << '\n';
	
	// pointer subscript notation
	cout << "\nPointer subscript notation:\n";

	for (int i = 0; i < size; ++i)
		cout << "bPtr[" << i << "] = " << bPtr[ i ] << '\n';

	// pointer offset notation
	cout << "\nPointer/offset notation:\n";

	for (int offset = 0; offset < size; ++offset)
		cout << "*(bPtr + " << offset << ") = " << *(bPtr + offset) << '\n';

	return 0;	
}
