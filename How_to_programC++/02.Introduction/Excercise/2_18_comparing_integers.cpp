// 2_18_comparing_integers
// Program compare two integers, and display larger number
// or equal
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int number1;
	int number2;

	cout << "Please enter two integers: "; // user input
	cin >> number1 >> number2; // save user input to variables
	
	if ( number1 > number2 ) 
		cout << number1 << " is larger." << endl; // display larger number
	
	if ( number1 < number2 )
		cout << number2 << " is larger." << endl; // display larger number
	
	if ( number1 == number2 )
		cout << "These numbers are equal." << endl; // display equal integers

	return 0;
}
