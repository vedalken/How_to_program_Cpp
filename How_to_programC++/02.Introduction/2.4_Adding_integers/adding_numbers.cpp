// adding_numbers.cpp
// Program use user input for calculating sum of two integers

#include <iostream> //allows program to perform input and output 

// function main begins program execution
int main()
{
	std::cout << "Enter first integer: "; // prompt user for data
	// first integer to add
	int number1;

	// read first integer from user to number1
	std::cin >> number1;

	std::cout << "Enter second integer: "; // prompt user for data
	// second integer to add
	int number2; 

	// read second integer from user to number2
	std::cin >> number2; 

	// sum of number1 and number2
	int sum;

	sum = number1 + number2; // add the numbers; store result in sum

	std::cout << "Sum is " << sum << std::endl; // display sum; end line

	return 0;
}
