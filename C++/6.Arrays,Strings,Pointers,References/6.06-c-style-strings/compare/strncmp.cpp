// strncmp.cpp
// Compare two strings with strncmp.cpp
#include <cstring>
#include <cstdio>
using std::strncmp; // cstring
using std::puts; // cstdio
int main()
{
	char str1[] = "string1";
	char str2[] = "string2";
	
	/* compare two strings */
	if ( strncmp( str1, str2, 6 ) != 0 )
		puts( "Strings does not match" );
	else 
		puts( "Strings matches" );

	return 0;	
}
