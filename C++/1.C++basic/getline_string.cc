#include <iostream>
#include <string>

using namespace std;

int main () {
	
	int i (5);
	string mystring;

	cout << "Enter some string: ";
	getline (cin, mystring);
	cout << "You entered: \"" << mystring << "\"\n";
	cout << i << "\n";

	return 0;
}
