// instr1.cpp - insert string into array
// using cin.getline to read line instead of one word
#include <iostream>
int main()
{
	using namespace std;
	// if buffer is to small, eofbit may be thrown!
	const int arraySize = 12; // buffer
	
	cout << "Enter your name: ";
	char array[ arraySize ];
	cin.getline( array, arraySize ); // may throw eofbit error! 
	cout << "What is your favorite dessert? ";
	char dessertName[ arraySize ];
	cin.getline( dessertName, arraySize ); // may throw eofbit error!

	cout << "Hi " << array << '\n';
	cout << "Your favorite dessert is " << dessertName << '\n';
	return 0;	
}
