// nonegative.cpp
// Use goto statement.
#include <iostream>
#include <cmath>

int main()
{
	using std::cout; // iostream
	using std::endl;
	using std::cin;
	using std::sqrt; // cmath

	tryAgain:
		double number;
		cout << "Enter non-negative number: ";
		cin >> number;

		// validate nonegative number; prompt message to user to
		// enter correct value
		if (number < 0.0) 
			goto tryAgain;

		cout << "You entered: " << number
			<< "\nsqrt = " << sqrt(number) << endl;

	return 0;	
}
