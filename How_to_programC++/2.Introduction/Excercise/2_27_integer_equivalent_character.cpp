// 2_27_integer_equivalent_character.cpp
// Program uses static_cast operator to convert character to integer
#include <iostream>

using namespace std;

int main()
{
	char cchar;
	
	cout << "Enter a ASCII character: ";
	cin >> cchar; // save input as character variable

	cout << static_cast< int >( cchar ) << endl; // convert ASCII character to integer

	return 0;	
} // end main 
