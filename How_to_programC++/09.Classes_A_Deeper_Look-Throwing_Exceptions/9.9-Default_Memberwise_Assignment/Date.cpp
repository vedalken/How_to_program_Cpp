#include <iostream>
#include "Date.h"

Date::Date(int day, int month, int year)
	: m_day(day), m_month(month), m_year(year)
{
}

void Date::print() const
{
	std::cout << m_day << "/" << m_month << "/" << m_year;
}

// This won't compile, because of const keyword!!
void Date::setDay(int day)
{
	m_day = day;
}
