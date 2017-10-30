// main.cpp
// Program calculates individual and total parking hours and its charges.
#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout; // iostream
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw; // iomanip
using std::ceil; // cmath

double calculateCharge( double parkingHours ); // calculate parking charge

int main()
{
	// Information for three customers
	int parkingNumber1 = 0; 	// parking number of first customer
	int parkingNumber2 = 0; 	// parking number of second customer	
	int parkingNumber3 = 0; 	// parking number of third customer

	double parkingHours1 = 0.0;	// parking hours of first customer
	double parkingHours2 = 0.0;	// parking hours of second customer
	double parkingHours3 = 0.0; // parking hours of third customer
	
	cout << "Input 3 customers parking info!\n";
	cout << "Enter parking number and number of parking hours  customer\n";
	
	// Read user input
	cin >> parkingNumber1 >> parkingHours1
		>> parkingNumber2 >> parkingHours2
		>> parkingNumber3 >> parkingHours3;

	// Calculate parking charges for each customer
	double parkingCharge1 = calculateCharge( parkingHours1 );
	double parkingCharge2 = calculateCharge( parkingHours2 );
	double parkingCharge3 = calculateCharge( parkingHours3 );

	// Total parking charges
	double totalCharges; 
	totalCharges = parkingCharge1 + parkingCharge2 + parkingCharge3;
	
	// Total hours parked for all three customers
	double totalHours;
	totalHours = parkingHours1 + parkingHours2 + parkingHours3;

	// Display information
	cout << left << setw(15) << "Parking number" << right << setw(10) << "Hours"  << setw(10) << "Charge" << endl;
	
	cout << left << setw(15) << parkingNumber1 << right << setw(10) << parkingHours1 << setw(10) << parkingCharge1 << endl
	     << left << setw(15) << parkingNumber2 << right << setw(10) << parkingHours2 << setw(10) << parkingCharge2 << endl
	     << left << setw(15) << parkingNumber3 << right << setw(10) << parkingHours3 << setw(10) << parkingCharge3 << endl;

	cout << left << setw(15) << "TOTAL" << right << setw(10) << totalHours << setw(10) << totalCharges << endl;

	return 0;	
}

// Calculate parking charge for a customer
// First three hours are charged $2.00, each hour for next three hours are charged $0.50, and
// 24-hour period charge $10.00
double calculateCharge( double parkingHours )
{
	double charge = 0.0; // parking charge in $
	
	if (parkingHours < 3.0) { // charge for first three parking hours
		charge = 2.00;
	}
	else if (parkingHours >= 3.0 && parkingHours < 6.0) // from 3 to 6 hours period
	{
		const double 	chargePerHour = 0.50; 	// each hour is charged $0.50
		const double 	baseCharge = 2.00;		// base charge for first three hours
		const int 		baseHour = 3;			// base hour when different charge is used

		double differ;	// time difference between parking hours and base hour
		differ = parkingHours - baseHour; // widening! (int baseHours -> double baseHours)
		
		// Difference must be round up for appropriate hour charge.
		int chargeFactor; 
		chargeFactor = ceil( differ );
		
		// For each hour, additional charge is added to base charge (for first three hours i.e. $2.00)
		// 				
		// 				charge = baseCharge + chargeFactor * chargePerHour
		//
		charge = baseCharge + chargeFactor * chargePerHour;
	} 
	else { // 24-hour period
		double chargePerDay = 10.00; // 24-hour period charge
		charge = chargePerDay;
	}

	return charge;
}

