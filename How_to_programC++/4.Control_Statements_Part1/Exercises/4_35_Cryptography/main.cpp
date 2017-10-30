// main.cpp
// Program encrypte 4 digit number.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void encryper(int number); // function prototype

int main()
{
	int number;
	
	// Prompt message to user
	cout << "Enter 4 digit number: ";
	cin >> number;
	
	cout << "\n\nEntered number: " << number << endl;
	
	// Display encrypted number
	cout << "Encrypted number: ";
	encryper(number);

	cout << endl;

	return 0;	
}// end main function
