// string.cpp
#include <iostream>
#include <string>
int main()
{
	using namespace std; // both iostream and string
	
	cout << "Enter your name: ";
	string str1;
	//cin >> str1;
	getline( cin, str1 );
	cout << "Hello, " << str1 << '!' << endl;
	cout << "Your name has " << str1.length()
		  << " characters in it.\n";
	cout << "The second character is: " << str1[1] << '\n';
	// replace with new name
	str1 = "Milos";
	cout << "Your new name is " << str1 << endl;
	cout << "Bye bye " << str1 << '!' << endl;
	
	char tmp[15] = "Milos";
	cout << "array of char: " << tmp;
	cout << "\nDisplay all array includin \'0\':\n";
	for (int i = 0; i < 15; ++i) 
	{
		if ( tmp[i] == '\0' ) {
			cout << '.';
			continue;
		}
		cout << tmp[i];
	}
	cout << '\n';
	return(0);	
}
