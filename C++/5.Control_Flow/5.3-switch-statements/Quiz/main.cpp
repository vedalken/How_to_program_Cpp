// main.cpp
// Program runs mathematical operaton on two numbers.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// Function prototype
double calculate(double number1, double number2, char op);

int main()
{
	double number1, number2;
	char mathOperator;

	cout << "Enter two numbers and mathematical operator: ";
	cin >> number1 >> number2 >> mathOperator;

	cout << "\nResult: ";
	cout << calculate(number1, number2, mathOperator) << endl;

	return 0;
}
