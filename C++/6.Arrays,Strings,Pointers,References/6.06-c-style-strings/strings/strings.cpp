// strings.cpp
// Store strings into array.
#include <iostream>
#include <cstring>
int main()
{
	using std::cout; // iostream
	using std::endl;
	using std::cin;
	using std::strlen; // cstring

	const int size = 15;
	char name1[ size ] = {};
	char name2[ size ] = "C++owboy"; // constant string or string literal
	cout << "Hi " << name2 << "!\n";
	cout << "What's your name? ";
	cin >> name1;
	cout << "Well " << name1 << ", nice to meet you.\n";
	cout << "Your name has " << strlen( name1 ) << " characters\n"
		<< "in array with " << sizeof name1 << " bytes.\n"
		<< "Total size of array is " << size << '\n';
	
	cout << "Initial character is \'" << name1[0] << '\'' << endl;
	// rename third element (element 2)
	name2[3] = '\0';
	cout << "First three characters of my name: "
		<< name2 << '\n';

	return 0;	
}
