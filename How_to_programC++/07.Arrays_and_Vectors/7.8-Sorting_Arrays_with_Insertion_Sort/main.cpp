// main.cpp
// Program sorts vector elements in ascending
// order using insertion sort.
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::setw; // iomanip

void displayArray( const int array[], int arraySize ); // function prototype

int main()
{
	const int arraySize = 10; // array size
	int data[ arraySize ] = { 34, 56, 4, 10, 77, 51, 93, 30, 5, 52 };

	// display array before sorting
	cout << "Unsorted array:" << endl;
	displayArray( data, arraySize );
	
	// Sort data in ascending order with insertion sort
	// Loop over array elements, which will be sorted
	// in ascending order
	for ( int iii = 1; iii < arraySize; ++iii )
	{
		int insert  = data[ iii ];	// insert item
		int moveItem = iii;			// location of moving item

		// Move gap to left (for correct place of "insert" value)
		// Move item, with index iii to left, if item, with index iii-1
		// is larger, or shift each element (index "moveItem-1") by 1 to right, 
		// if this element is greater than "insert" element (swap element).
		while ( moveItem > 0 && (data[ moveItem-1 ] > insert) )
		{	
			// shift greater element to the right by 1
			data[ moveItem ] = data[ moveItem - 1 ];

			// Move "gap" (previous item value, for us is junk value) in left
			// Why junk value, or gap? 
			// 		Because this element is overriden by new, shifted one, from
			// 		the left side of an array, or placed by "insert" item (when 
			// 		reached out of while loop)
			moveItem--;
		}

		// moveItem is already decreased, so while statment is false
		// This is new index for "insert" item
		data[ moveItem ] = insert;
	}//end for loop

	cout << "Sorted array:" << endl;
	displayArray( data, arraySize );

	return 0;	
}// end main 

// Display array
void displayArray( const int array[], int arraySize )
{
	for ( int iii = 0; iii < arraySize; ++iii )
		cout << setw(4) << array[ iii ];
	
	cout << endl; // new line
}// end displayArray function
