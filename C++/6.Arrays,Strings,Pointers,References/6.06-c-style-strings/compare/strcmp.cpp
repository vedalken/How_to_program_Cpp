// strcmp.cpp
// Compare two strings.
#include <cstring>
#include <cstdio>
using std::strcmp; // cstring
using std::puts; // cstdio
int main()
{
	char str1[] = "string1";
	char str2[] = "string2";
	
	/* compare two strings */
	if ( strcmp( str1, str2 ) != 0 )
		puts( "Strings does not match" );
	else 
		puts( "Strings match" );

	return 0;	
}
