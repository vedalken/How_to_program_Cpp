// vowels.cpp
// Determine number of vowels in a string.
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	const int arraySize = 6; // string size
	char name[ arraySize ] = "Milos"; // of course, my name
	int vowels = 0; // number of vowels in string
	// declare pointer looping over string of characters
	// and counting vowels
	for ( char* cPtr = name; cPtr < name + arraySize; ++cPtr )
	{
		switch( *cPtr )
		{
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				++vowels; // count vowels
				break;
		}
	}
	cout << name << " has " << vowels << " vowels" << endl;
	return 0;	
}
