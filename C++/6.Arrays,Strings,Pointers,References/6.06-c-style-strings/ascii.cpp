// ascii.cpp
// Print string characters in ASCII code.
#include <iostream>
int main()
{
	using std::cout;
	using std::endl;

	// stringName contains size() + 1 (for '\0')
	char stringName[] = "string"; 

	// print size of string
	cout << "string name: " << stringName << '\n';
	cout << "number of chars: " << sizeof stringName << '\n';
	
	for ( size_t nChar = 0; nChar < sizeof(stringName); ++nChar )
		cout << static_cast<int>( stringName[ nChar ] ) << " ";
	
	cout << '\n';
	return(0);	
}
