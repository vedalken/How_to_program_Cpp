// askForNumber.cpp
// Program repeatedly prompt message to user to enter
// number from 1 to 9, until correct number is entered.
// Display array index with that element (there may be
// more than just one!)
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	// create array with 9 elements
	const int nArraySize = 9;
	int nArray[ nArraySize ] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	
	int nElement = 0;
	// prompt message to user, repeatedly, until
	// correct number is entered
	do {
		cout << "Enter number between 1 and 9: ";
		cin >> nElement;
	}while( nElement < 1 || nElement > 9 );

	// search for element in array and when found 
	// display array index
	for (int nIndex = 0; nIndex < nArraySize; ++nIndex) 
	{
		if (nArray[ nIndex ] == nElement) {
			cout << "Array element: " << nIndex << endl;
		}
	}

	return 0;	
}
