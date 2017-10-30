// main.cpp
// Input two numbers, and program determines if the second
// number is a multiple of the first.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::boolalpha;

// Function determines if second number is a multiple ot the 
// first.
// If second number is a multiple, function return true(1), 
// otherwise false(0).
bool multiple( int first, int second ); 

int main()
{
	cout << "Enter ctrl-c to exit!" << endl;
	cout << "Enter two numbers: "; 
	int number1;
	int number2;
	cin >> number1 >> number2; // read two input numbers

	while (true) {
		// Display message
		cout << "Second is multiple of the first: " 
			<< boolalpha << multiple( number1, number2 ) << endl;
		
		// Prompt message to user
		cout << "\nEnter two numbers: "; 
		cin >> number1 >> number2; // read two input numbers
	}

	return 0;
}

// Function returns true, if second number is a multiple of
// the first, else false.
bool multiple( int first, int second )
{
	return !( first % second ); 
}
