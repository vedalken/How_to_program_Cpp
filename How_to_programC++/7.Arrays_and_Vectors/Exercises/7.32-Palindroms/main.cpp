// main.cpp
// Determine is string is palindrome - word is spelled
// the same way forward and backward.
#include <iostream>
#include <string>
using std::cout; // iostream
using std::endl;
using std::cin;
using std::string; // string
using std::getline;

bool palindrome( string );

int main()
{
	cout << "Input string: ";
	string strInput;
	getline( cin, strInput );
	
	// check if word is palindrome
	// mark word if palindrome
	bool isPalindrome = true;

	// one counter goes forward and the other 
	// goes from the end
	for ( size_t fw = 0, bw = strInput.length()-1; 
		fw != bw ; ++fw, --bw ) 
	{
		// compare first and last character
		if ( strInput[ fw ] == strInput[ bw ] ) {
			;
		} else {
			isPalindrome = false;
			break;
		}
	}
	
	// recursive string test
	isPalindrome = palindrome( strInput );

	if ( isPalindrome ) {
		cout << "Palindrome." << endl;
	} else {
		cout << "Not palindrome." << endl;
	}

	return 0;	
}

///
/// recursive check if word is palindrome
bool palindrome( string str ) 
{
	size_t strLength = str.length();
	// last character remains
	if ( strLength == 1 )
		return true;
	
	// compare characters (first and last)
	if ( str[0] != str[ strLength-1 ] )
		return false;

	unsigned twoChar = 2;
	
	// return true for all matching characters
	return 1 * palindrome( str.substr( 1, strLength-twoChar ) );	
}
