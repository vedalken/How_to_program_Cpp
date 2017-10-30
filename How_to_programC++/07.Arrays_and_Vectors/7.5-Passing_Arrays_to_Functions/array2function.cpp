// array2function.cpp
// Pass array to function, which is, by default,
// passed by reference. Array is modified by 
// caller. Array's element, when passed to a function,
// is by default passed by value.
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;

void modifyArray( int [], int );
void modifyElement( int );

int main()
{
	const int arraySize = 5; // array size
	int a[ arraySize ] = { 1, 2, 3, 4, 5 }; // array elements
	
	cout << "Effects of passing entire array by reference:"
		 << "\nThe values of original array are:\n";

	// display array
	for ( int i = 0; i < arraySize; ++i )
		cout << "a[" << i << "]=" << setw( 3 ) << a[i] << endl;
 
 	cout << endl;
	// pass array "a" to modifyArray by reference
	modifyArray( a, arraySize );
	cout << "Modified array:" << endl;
	
	for ( int i = 0; i < arraySize; ++i )
		cout << "a[" << i << "]=" << setw( 3 ) << a[i] << endl;
	
	cout << "\n\nEffect of passing array element by value"
		 << "\na[3] before modification: ";
	cout << a[3] << endl;
	cout << endl;
	
	modifyElement( a[3] );
	cout << "Modify element: " << a[3] << endl;
	
	return 0;	
}

// modify "b" by multiplying each element by 2
// array "b" points to original array "a" in memory!
void modifyArray( int b[], int sizeOfArray )
{
	//multiply each element by 2
	for ( int j = 0; j < sizeOfArray; ++j )
		b[ j ] *= 2;
}//end function modifyArray

// "element" is local copy of array element a[3] 
// which is passed from main
void modifyElement( int element )
{
	element *= 2;
	cout << "Value of element in modifyElement: " << element << endl;
}// end function modifyElement
