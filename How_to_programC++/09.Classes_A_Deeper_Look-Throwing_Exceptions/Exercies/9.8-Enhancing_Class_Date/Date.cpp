#include <iostream>
#include <stdexcept>
#include <climits>
#include <iomanip>
#include "Date.h"

Date::Date(int day, int month, long long int year)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}

// This won't compile, because of const keyword!!
void Date::setDay(int day)
{
    if (day > 0 && day <= 31) {
	    m_day = day;
    }
    else {
        throw std::invalid_argument("Day must be 1-31.");
    }
}

void Date::setMonth(int month)
{
    if (month > 0 && month <= 12) {
        m_month = month;
    }
    else {
        throw std::invalid_argument("Month must be 1-12.");
    }
}

void Date::setYear(long long int year)
{
    if (year < LLONG_MIN || year > LLONG_MAX) {
        throw std::invalid_argument("Year number is too big.");
    }
    else {
        m_year = year;
    }
}

void Date::nextDay()
{
    try {
        setDay(m_day + 1);
    }
    catch (const std::invalid_argument &ia_d) {
        try {
            setMonth(m_month + 1);
            setDay(1);
        }
        catch (const std::invalid_argument &ia_m) {
            try {
                setYear(m_year + 1);
                setMonth(1);
                setDay(1);
            }
            catch (const std::invalid_argument &ia_y) {
                std::cout << "Invalid argument: " << ia_y.what() << std::endl;
            } //year
        } //month
    } //day
}

void Date::print() const
{
	std::cout << std::setw(2) << std::setfill('0') << m_day 
        << "/" << std::setw(2) << m_month << "/" << m_year;
}

