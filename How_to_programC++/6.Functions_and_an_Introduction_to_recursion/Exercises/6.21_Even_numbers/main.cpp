// main.cpp
// Program determines whether input number is even of odd.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

bool isEven( int ); // determine if number is odd or even

int main()
{
	int number;
	// Prompt message to user to enter integer number
	do {
		cout << "\nEnter integer (0 to exit): "; // prompt message to user
		cin >> number;

		cout << "Is even: " << boolalpha << isEven( number ) << endl;
	} while( number != 0 );

	return 0;
}

// Function determines whether number is even or odd.
// Return true if number is even, otherwise false.
bool isEven( int number )
{
	return !(number % 2);
}
