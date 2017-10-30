// countSpace.cpp
// Count spaces in a string.
#include <iostream>
#include <cstring>
using std::cout; // iostream
using std::endl;
using std::cin;
using std::strlen; // cstring
int main()
{
	char someStr[ 255 ] = {};
	cout << "Enter string: ";
	cin.getline( someStr, 255 ); /* read string */
	
	// count spaces in string
	int countSpaces = 0;
	for ( size_t i = 0; i < strlen( someStr ); ++i )
	{
		if ( someStr[i] == ' ' )
			++countSpaces;
	}

	cout << "Total number of spaces: " << countSpaces << endl;
	return 0;	
}
