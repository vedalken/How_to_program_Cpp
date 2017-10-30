// strlen.cpp
// Determine string length without null terminate
// character.
#include <iostream>
#include <cstring>
using std::cout;
using std::strlen; // cstring
int main()
{
	char myStr[30] = "Some string name";
	
	cout << "string name: " << myStr;
	cout << "\nstring sizeof: " << sizeof myStr;
	cout << "\nstring length: " << strlen( myStr );
	cout << '\n';
	return 0;	
}
