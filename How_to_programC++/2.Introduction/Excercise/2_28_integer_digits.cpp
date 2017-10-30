// 2_28_integer_digit.cpp
// Program uses five-digit integer input, separates the integer into
// its digits and print them separated by three spaces each.
#include <iostream>

int main()
{
	using namespace std;
	
	unsigned int number;
	
	cout << "Enter five digit integer: ";
	cin >> number;

	int digit5;

	// remineder after division with 10 will give you last digit
	// of a number
	digit5 = number % 10;

	int a1;
	int digit4;
	
	// go to next digit in five-digit integer number 
	a1 = number / 10;

	// found digit
	digit4 = a1 % 10;

	int a2;
	int digit3;
	a2 = a1 / 10;
	digit3 = a2 % 10;

	int a3;
	int digit2;
	a3 = a2 / 10;
	digit2 = a3 % 10;

	int a4;
	int digit1;
	a4 = a3 / 10;
	digit1 = a4 % 10;

	// display digits separated by three spaces
	cout << digit1 << "   " << digit2 << "   " <<
		    digit3 << "   " << digit4 << "   " << digit5 << endl; 

	return 0;
} // end main
