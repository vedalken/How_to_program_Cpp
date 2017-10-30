// main.cpp
// Demonstrate using static and automatic storage
// arrays.
#include <iostream>
using std::cout;
using std::endl;

void staticArrayInit( void );	// function prototype
void autoArrayInit( void );		// function prototype
const int arraySize = 3;		// static and automatic array size

int main()
{
	cout << "First call to each function:" << endl;
	staticArrayInit();
	autoArrayInit();
	cout << "\n\n";

	cout << "Second call to each function:" << endl;
	staticArrayInit();
	autoArrayInit();
	cout << endl;

	return 0;
}//end main function

// Initialize static array once and before function exit
// add 5 to each element
void staticArrayInit( void )
{
	static int array[ arraySize ]; // compiler initializes elements to 0!

	cout << endl;
	cout << "Initialized array in staticArrayInt:" << endl;

	// display array content
	for (int i = 0; i < arraySize; ++i) {
		cout << "array[" << i << "] = " << array[i] << " ";
	}
	
	cout << endl;
	cout << "Values on exit staticArrayInt:" << endl;

	// add 5 to each element in array
	for (int i = 0; i < arraySize; ++i) {
		cout << "array[" << i << "] = " << ( array[i] += 5 ) << " ";
	}
}// end function staticArrayInit

// Initialize automatic array every time function call is made.
// Before exit add 5 to each element.
void autoArrayInit( void )
{
	int array[ arraySize ] = {1,2,3}; // initialize array
	
	cout << endl;
	cout << "Initialized array in autoArraySize:" << endl;
	
	// display array elements
	for (int i = 0; i < arraySize; ++i) {
		cout << "array[" << i << "] = " << array[i] << " ";
	}

	cout << endl;
	cout << "Values on exit autoArraySize:" << endl;

	// add 5 to each element in array
	for (int i = 0; i < arraySize; ++i) {
		cout << "array[" << i << "] = " << ( array[i] += 5 ) << " ";
	}	
}// end function autoArraySize







