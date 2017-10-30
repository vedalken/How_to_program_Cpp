// strncpy.cpp
// Copy string, safer than strcpy C function.
#include <iostream>
#include <cstring>
#include <cstdio>
using std::cout; // iostream
using std::endl;
using std::strncpy; // ctring
using std::puts; //cstdio

void printString( const char* const );
void printString( const char* const, size_t );
int main()
{
	const char myStr[] = "some string to copy!";
	char str1[ 30 ] = {};
	char str2[ 30 ] = {};
	cout << "\nMy string:\n";
	printString( myStr, sizeof myStr );
	cout << "\nstr1:\n";
	printString( str1, sizeof str1 );
	cout << "\nstr2:\n";
	printString( str2, sizeof str2 );

	/* copy to sized buffered (overflow safer) */
	strncpy( str1, myStr, sizeof myStr );
	cout << "\nprintString( , )\n";
	printString( str1, sizeof myStr );
	cout << "\nprintString():\n";
	printString( str1 );
	puts( str1 );

	/* partial copy (only 10 char) */
	strncpy( str2, myStr, 10 );
	str2[10] = '\0'; /* null character manually added */
	cout << "\nprintString():\n";
	printString( str2 );
	cout << endl;

	return 0;	
}

// print string
void printString( const char* const someString )
{
	for ( const char* chPtr = someString; *chPtr != 0; ++chPtr )
		cout << *chPtr;
}//end function

void printString( const char* const someString, size_t stringLength )
{
	for ( size_t i = 0; i < stringLength; ++i ) {
		if ( *(someString + i) == '\0' )
		{
			cout << ".";
			continue;
		}
		cout << someString[ i ];
	}
}

