// main.cpp
// Read 20 numbers in range from 10 to 100.
// Display only those, not duplicates, if any.
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>
using std::cout; 	// iostream header
using std::endl;
using std::setw; 	// iomanip header
using std::vector;	// vector header
using std::time; 	// ctime header
using std::srand;	// cstdlib header
using std::rand;

// function prototype
void displayArray( const int [], const int );
void displayVector( const vector<int> & );
bool bFindElement( const vector<int> &, int );

int main()
{
	srand( time(0) ); // seed generator

	// lower and upper bound in which numbers are
	// generated
	const int nLBound = 10;
	const int nUBound = 30; 

	const int nArraySize = 20; // array size
	int anArray[ nArraySize ]; // array declaration

	// initialize array with random numbers from
	// lower bound to upper bound numbers
	for ( int i = 0; i < nArraySize; ++i )
		anArray[ i ] = nLBound + rand() % ( nUBound-nLBound );

	vector<int> nvecNoDup;	// vector with no duplicates
	vector<int> nvecDup;	// vector with duplicates

	for ( int i = 0; i < nArraySize; ++i )
	{
		// save every item without any duplicates already
		// stored in array
		// also save element duplicate
		if (! bFindElement( nvecNoDup, anArray[ i ] ) )
			nvecNoDup.push_back( anArray[ i ] );
		else
			nvecDup.push_back( anArray[ i ] );
	}
	
	// display all numbers
	cout << "All number:" << endl;
	displayArray( anArray, nArraySize );

	// display without duplicates
	cout << "No duplicates:" << endl;
	displayVector( nvecNoDup );
	
	// display duplicates
	cout << "Duplicates:" << endl;
	displayVector( nvecDup );
	
	return 0;	
}//end main

////
////
//// display array
void displayArray( const int anArray[], const int nArraySize )
{
	for ( int index = 0; index < nArraySize; ++index )
		cout << setw(4) << anArray[ index ];

	cout << "\n"; // new line
}//end displayArray function

////
////
//// display vector
void displayVector( const vector<int> & nvecArray )
{
	for ( size_t index = 0; index < nvecArray.size(); ++index )
		cout << setw(4) << nvecArray[ index ];

	cout << "\n"; // new line
}//end displayVector

////
////
//// search for key in array, if there is none, result is 0,
//// otherwise is 1
bool bFindElement( const vector<int> & nvecArray, int nKey )
{
	for ( size_t index = 0; index < nvecArray.size(); ++index )
	{
		// check for element in array
		if ( nKey == nvecArray[ index ] )
			return true;
	}
	
	// no key found in array
	return false;
}// return bCheckDupes
