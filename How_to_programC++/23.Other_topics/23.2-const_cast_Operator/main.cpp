#include <iostream>
#include <cstring>
#include <cctype>

const char* maximum( const char* first, const char* second )
{
	return (std::strcmp( first, second ) >= 0 ? first : second );
}

int main()
{
	char s1[] = "hello";
	char s2[] = "goodbye";

	// discard const-ness from function return
	char *maxPtr = const_cast<char *>( maximum(s1, s2) );

	std::cout << "The larger string is " << maxPtr << std::endl;

	for ( char *ptr = maxPtr; *ptr != '\0'; ++ptr ) {
		*ptr = std::toupper( *ptr );
	}

	std::cout << "The larger string capitalized is: " << maxPtr << std::endl;

	return 0;
}
