// 2_16_two_numbers.cpp
// Program calculates sum, product, difference, and quotient
// of two integer numbers

#include <iostream>

int main()
{
	int number1;
	int number2;

	std::cout << "Please enter two integer numbers: "; // user input two inetgers
	std::cin >> number1 >> number2; // read user input
	
	// Calculate sum
	std::cout << "\tSum: ";
	std::cout << ( number1 + number2 ) << std::endl; // display sum

	// Calculate difference 
	std::cout << "\tDifference: ";
	std::cout << ( number1 - number2 ) << std::endl; // display difference

	// Calculate product
	std::cout << "\tProduct: ";
	std::cout << ( number1 * number2 ) << std::endl; // display product

	// Calculate quotient
	std::cout << "\tQuotient: ";
	std::cout << ( number1 / number2 ) << std::endl; // display quotient

	return 0; 
} // end main function
