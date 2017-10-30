// calculate.cpp
// Function calculate appropriate mathematical operation
// on two numbers and a character (operator)
#include <cstdlib>
using std::exit;

double calculate(double number1, double number2, char op)
{
	// Test for operator match
	switch (op)
	{
		case '+': // Addition operator
			return (number1 + number2);

		case '-': // Subtraction operator
			return (number1 - number2);

		case '*': // Multiplication operator
			return (number1 * number2);

		case '/': // Division operator
			if (number2 == 0) {
				return 0; // break switch if number2 is 0!
			}
			return (number1 / number2);

		default:
			exit(1); // exit function; nothing to do
	}// end switch statement
} // end calculate function
