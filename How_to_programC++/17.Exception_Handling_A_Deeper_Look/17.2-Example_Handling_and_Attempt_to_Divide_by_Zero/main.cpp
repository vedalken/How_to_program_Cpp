#include <iostream>
#include "divide_by_zero_exception.h"

double quotient(int a_number1, int a_number2)
{
	if (a_number2 == 0) {
		throw DivideByZeroException();
	}

	return (static_cast<double>(a_number1) / a_number2);
}

int main()
{
	int number1;
	int number2;

	std::cout << "Enter two integers (end-of-file to end): ";

	while (std::cin >> number1 >> number2)
	{
		try {
			double number = quotient(number1, number2);
			std::cout << "This quotient is " << number << std::endl;
		}
		catch (const DivideByZeroException& dbze) {
			std::cout << "Exception occured: " << dbze.what() << std::endl;
		}

		std::cout << "Enter two integers (end-of-file to end): ";
	}

	return 0;
}
