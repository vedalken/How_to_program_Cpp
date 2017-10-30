// main.cpp
// Linear search of an array.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// function prototype
int linearSearch( const int array[], int key, int arraySize );

int main()
{
	const int arraySize = 100; // array size
	int a[ arraySize ]; // declare array with size arraySize

	// initialize array with values 2*index, index = 0,1,2,...,99
	for ( int i = 0; i < arraySize; ++i )
		a[ i ] = 2 * i;

	// read search key, entered by user
	cout << "Enter search key: ";
	int searchKey;
	cin >> searchKey;

	// get index of key in array, if there is any
	int keyArrayIndex;
	keyArrayIndex = linearSearch( a, searchKey, arraySize );

	if ( keyArrayIndex >= 0 )
		cout << "Found value in element " << keyArrayIndex << endl;
	else
		cout << "Value not found!" << endl;

	return 0;	
}// end main

// Search for "key" value in array of a size "arraySize"
// Function return subscript of element if key is found, otherwise
// -1 is returned	
int linearSearch( const int array[], int key, int arraySize )
{
	for ( int i = 0; i < arraySize; ++i )
	{
		if ( array[i] == key ) // look for key
			return i; // key found
	}

	return -1; // key not found
}// end linearSearch function
