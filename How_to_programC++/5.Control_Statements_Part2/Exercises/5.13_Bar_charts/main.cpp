// main.cpp
// Read five numbers. For each number display as many asterixes in
// a separate row.
#include <iostream>
using std::cout;
using std::cin;

int main()
{
	int count = 0;
	
	while (count < 5)
	{
		int number;
		cin >> number;	// read a number

		// Display asterixes
		for (int i = 0; i < number; ++i) {
			cout << "*";
		}

		cout << "\n"; 	// next line to read new integer
		++count; 		// count entered numbers
	}

	return 0;	
}
