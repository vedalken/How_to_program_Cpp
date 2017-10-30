// at.cpp
// Test vector function member at.
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vecArray( 10 ); // initialiaze 10 elements to 0!

	// set each element to some value
	for ( size_t index = 0; index < vecArray.size(); ++index )
		vecArray.at( index ) = index;

	// display array
	cout << "\nArray:\n";
	for ( size_t i = 0; i < vecArray.size(); ++i )
		cout << vecArray.at( i ) << endl;
	
	cout << endl; // new line

	return 0;	
}
