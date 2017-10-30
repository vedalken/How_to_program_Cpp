// strcat.cpp
// String concatenate.
#include <cstdio> 
#include <cstring>
using std::puts; // cstdio
using std::strcat; // cstring
int main()
{
	char someString[80] = {};
	/* concatenate strings */
	strcat( someString, "these ");
	strcat( someString, "strings ");
	strcat( someString, "are ");
	strcat( someString, "concatentated");
	puts( someString ); /* print string */
	return 0;	
}
