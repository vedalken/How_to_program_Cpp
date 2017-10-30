// Date.cpp
// Date class implementation, separated from interface
// Class display date as an input in one of the standard form.
#include <iostream>
#include "Date.h" // class Date forward declaration 
using std::cout;
using std::endl;

// constructor initialization
// abbreviation: month m, day d, year y
Date::Date(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
}

// set and get month 
void Date::setMonth(int m) 
{ 
	// validation
	if (m <= 12) {
		month = m;
	}
	// otherwise set to 1
	if (m > 12) {
		month = 1;
		cout << "Invalid month! Set to January." << endl;
	}
} 
int	Date::getMonth() { return month; }

// set and get day
void Date::setDay(int d) 
{
	// validation
	if (d <= 31) {
		day = d; 
	}
	// set to 1
	if (d > 31) {
		day = 1;
		cout << "Invalid day! Set to 1." << endl;
	}
}
int	Date::getDay() { return day; }

// set and get year
void Date::setYear(int y) { year = y; }
int Date::getYear() { return year; }

// display date in format month/day/year
void Date::displayDate()
{
	cout << "\n" << getMonth() << "/" << getDay() << "/" << getYear() << endl;
}
