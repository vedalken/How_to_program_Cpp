// strncat.cpp
// String concatenates using strncat function.
#include <cstring>
#include <cstdio>
using std::strcpy; // cstring
using std::strncat;
using std::puts; // cstdio
int main()
{
	char str1[30] = {};
	char str2[30] = {};
	strcpy( str1, "to be or " );
	strcpy( str2, "not to be No. 1 " );
	strncat( str1, str2, 9 );
	puts( str1 );
	return 0;	
}
