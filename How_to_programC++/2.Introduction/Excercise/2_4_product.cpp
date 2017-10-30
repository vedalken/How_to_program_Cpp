// 2_4_product.cpp
// Exercise 2.4 on page 58.
// Function calculates product of three integers

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int number1, number2, number3;	// multiplied integers

	cout << "Enter three integer numbers: "; // user input data
	cin >> number1 >> number2 >> number3;	// read input data 

	cout << "Product " << number1 << "*" << number2; // display multiplied numbers
	cout << "*" << number3 << " is ";
	
	int product;
	product = number1 * number2 * number3; // product of integer multiplication
	cout << product << endl; // display result; end line

	return 0;

} // end main function
