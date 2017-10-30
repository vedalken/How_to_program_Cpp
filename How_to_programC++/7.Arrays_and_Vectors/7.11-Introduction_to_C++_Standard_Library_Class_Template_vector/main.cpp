// main.cpp
// Manipulate arrays with vector object from STL.
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
using std::cout; // iostream header
using std::cin;
using std::endl;
using std::setw; // iomanip header
using std::vector; // vector header; vector constructor
using std::out_of_range; // stdexcept header

void outputVector( const vector<int> & ); // function prototype
void inputVector( vector<int> & );	

int main() 
{
	vector<int> integers1( 7 ); // declare array with 7 integers
	vector<int> integers2( 5 ); // declare array with 10 integers
	
	// output vector with default initialization
	cout << "integers1 size: " << integers1.size() << endl
		 << "Vector integers1 default initialization:" << endl;
	outputVector( integers1 );
	cout << "integers2 size: " << integers2.size() << endl
		 << "Vector integers2 default initialization:" << endl;
	outputVector( integers2 );
	
	// input numbers
	cout << "\nInput " << integers1.size() + integers2.size() 
		 << " numbers:" << endl;
	inputVector( integers1 );
	inputVector( integers2 );
	
	// display arrays after user input
	cout << "\nintegers1 values:" << endl;
	outputVector( integers1 );
	cout << "\nintegers2 values:" << endl;
	outputVector( integers2 );

	// inequality operator with vector objects
	cout << "\nEvaluating integers1 != integers2" << endl;
	if ( integers1 != integers2 )
		cout << "integers1 not equal integers2!" << endl;

	// create third vector as copy of integers1
	vector<int> integers3( integers1 );

	cout << "integers3 size: " << integers3.size() << endl
		 << "Vector integers3 default initialization:" << endl;
	outputVector( integers3 );
	
	// assigne one vector to another
	cout << "\nAssigne vector integers2 to integers1:" << endl;
	integers1 = integers2;
	cout << "integers1:" << endl;
	outputVector( integers1 );
	cout << "integers2:" << endl;
	outputVector( integers2 );
	
	if ( integers1 == integers2 )
		cout << "integers1 equals integers2!" << endl;
	
	cout << "\nintegers1[2]=" << integers1[ 2 ] << endl;
	cout << "\nassign 1000 to integers1[2]:" << endl;
	integers1[ 2 ] = 1000;
	cout << "integers1[2]=" << integers1[ 2 ] << endl;
	outputVector( integers1 );
	
	// manipulate (catch) exception
	try 
	{
		// display element 1040, if exists that big array,
		// if not, exception is immediately returned.
		// Exception is read by catch statement. Catched
		// exception type have to be defined in brackets!
		cout << integers1.at( 40 ) << endl; // ERROR: out of range
	} 
	catch ( const out_of_range & oor ) // exception type declaration
	{
		// display exception 
		cout << "An exception occured: " << oor.what() << endl;
	}
}// end main

// output vector elements using [] to access them
void outputVector( const vector<int> & array ) 
{
	size_t i; // declare unisigned int
	
	// display elements in vector
	for ( i = 0; i < array.size(); ++i ) 
	{
		cout << setw(8) << array[i];
	
		if ( (i+1) % 4 == 0 )
			cout << endl;
	}
	
	// put addition new line for numbers with reminder
	// after division with 4, not equal 0
	if ( i % 4 != 0 )
		cout << endl;
}//end outoputVector

// read numbers an put into "array" in same order
void inputVector( vector<int> & array )
{
	for ( size_t element = 0; element < array.size(); ++element )
		cin >> array[ element ];
}//end inputVector
