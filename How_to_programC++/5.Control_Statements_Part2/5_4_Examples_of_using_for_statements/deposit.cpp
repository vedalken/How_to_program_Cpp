// deposit.cpp
// Compound interest calculation with for statement. 
// Person invest some money. Program determines amount of money
// person earned each year for ten years.
// Formula for determining amounts (per year)
//
// 			p * (1 + r)^n
//
// where p is initial amount, r is annual rate, an n is number of years
#include <iostream>
#include <iomanip>
#include <cmath>	// pow function call
// iostream header
using std::cout;
using std::endl;
// iomanip header
using std::setw;		// set width of displayed text, with right (default) allignment
using std::fixed;
using std::setprecision;
// cmath header
using std::pow;

int main()
{
	// Display header
	cout << "Year" << setw(21) << "Amount on deposit" << endl;

	// Set floating-point precision display
	cout << fixed << setprecision(2);

	double initialAmount = 1000.0; 		// initial person's deposit amount
	double annualInterestRate = 0.05;	// annual interest rate
	double amountPerYear;				// amount on deposit after each year
	double value;
	
	value = 1.0 + annualInterestRate;

	// Calculate amount on deposit for each of ten years
	for (int year = 1; year <= 10; ++year)
	{
		// Calculate new ammount on deposit for each of ten years
		amountPerYear = initialAmount * pow(value, year);

		// Display year and current annual amount
		cout << setw(4) << year << setw(21) << amountPerYear << endl;
	}

	return 0;
}
