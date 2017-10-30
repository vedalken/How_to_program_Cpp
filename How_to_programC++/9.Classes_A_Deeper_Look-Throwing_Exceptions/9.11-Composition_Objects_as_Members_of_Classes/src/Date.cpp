#include <iostream>
#include <stdexcept>
#include <array>
#include "Date.h"

// constructor confirms proper value for month
// utility function checks day to confirm proper
// value for a day
Date::Date(int year, int month, int day)
{
	m_year = {year}; // could validate year

	// validate month
	if (month > 0 && month <= months) {
		m_month = {month};
	}
	else {
		throw std::invalid_argument("month must be 1-12");
	}
	
	// validate day
	m_day = checkDay(day);

	std::cout << "Date object constructor for date ";
	print();
	std::cout << '\n';
}


// print Date object in form day/month/year
void Date::print() const
{
	std::cout << m_day << "/" << m_month << "/" << m_year;
}


// output Date object to show when destructor is called
Date::~Date()
{
	std::cout << "Date object destructor is called. ";
	print();
	std::cout << '\n';
}


// utility function check
int Date::checkDay(int day) const
{
	static const std::array<int, months+1> daysPerYear = 
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// check valid day
	if (day > 0 && day <= daysPerYear[m_month])
		return day;

	// February 29 check for leap year
	if (m_month == 2 && day == 29)
	{
		if ((day % 400 == 0) || ((day % 4 == 0) && (day % 100 != 0)))
			return day;
	}

	throw std::invalid_argument("Invalid day for current month and year");
}
