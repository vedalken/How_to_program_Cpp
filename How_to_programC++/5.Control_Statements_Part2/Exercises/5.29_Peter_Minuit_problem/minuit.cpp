// minuit.cpp
// Peter Minuit, in 1626, purchased Manhattan Island for $24.00 in barter.
// Calculate amount of interest on deposit if that money had been kept on deposit
// until this day (386 years, year 2012).
// Compound interest varies form 5% to 10%.
#include <cmath>	// power function
#include <iostream>	// cout, endl function
#include <iomanip>	// setprecision function
// cmath header
using std::pow;
// iostream header
using std::cout;
using std::endl;
// iomanip header
using std::setprecision;
using std::fixed;

int main()
{
	const int purchasedYear = 1626; // Minuit purchased year
	const int currentYear	= 2012;	// currect year
	double initialAmount	= 24.0;	// initial purchsed amount
	double amountOfInterest; // amount of interest

	int years; // number of years passed from isladn purchased
	years = currentYear - purchasedYear;

	// Calculate amount of interest for number of years passed for compound interest
	// rate form 5% to 10%.
	for (int interestRate = 5; interestRate <= 10; ++interestRate) 
	{	
		double rate = interestRate / 100.0;

		// Calculate amount of interest for different interest rates
		amountOfInterest = initialAmount * pow(1 + rate, years);
		
		// Display information on interest amount
		cout << "Amount of interest: " << fixed << setprecision(0) << amountOfInterest << endl;
	}

	return 0;
}
