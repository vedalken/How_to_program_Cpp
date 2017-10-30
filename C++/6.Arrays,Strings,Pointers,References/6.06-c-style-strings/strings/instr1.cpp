// instr1.cpp - insert string into array
// read string with cin
#include <iostream>
int main()
{
	using namespace std;
	const int arraySize = 30;
	
	cout << "Enter your name: ";
	char array[ arraySize ] = {};
	cin >> array;
	cout << "What is your favorite dessert? ";
	char dessertName[ arraySize ] = {};
	cin >> dessertName;

	cout << "Hi " << array << '\n';
	cout << "Your favorite dessert is " << dessertName << '\n';
	cin >> dessertName;
	cout << "Missing word, not read by cin: " 
		<< dessertName << '\n';
	return 0;	
}
