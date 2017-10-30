// switch.cpp
// Program test simple switch statement.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int number = 1; // initialize to one

	switch (number) {
		case 0: // does not match! Skipped.
			cout << "0" << endl;
		case 1: // match! Execution begins at next statement
			cout << "1" << endl;
		case 2:	// this is also executed
			cout << "2" << endl;
		case 3: // this is also executed
			cout << "3" << endl;
		default: // this is also executed
			cout << "Unknown." << endl;
	}

	return 0;
}
