// buffer.cpp
// Store string into buffer.
#include <iostream>
using namespace std;
int main()
{
	char stringName[ 255 ];
	cin.getline( stringName, 255 );
	//cin >> stringName; // store string into array of chars
	cout << "String name: " << stringName << '\n';

	return 0;	
}
