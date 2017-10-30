//strings.cpp
//Manipulate strings.
#include <iostream>
#include <cstring>
using std::cout; // iostream
using std::endl;
using std::strcpy; // cstring
int main()
{
	const char myString[] = "some string name";
	char str1[40] = {};
	char str2[40] = {};
	strcpy( str1, myString );
	strcpy( str2, "successful" );
	cout << "my string: " << myString 
		<< " string sizeof: " << sizeof myString;
	cout << "\nstr1: " << str1;
	cout << "\nstr2: " << str2 << endl;
	return 0;	
}
