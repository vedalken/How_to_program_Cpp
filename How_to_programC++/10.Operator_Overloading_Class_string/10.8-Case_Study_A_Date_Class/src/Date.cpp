#include <stdexcept>
#include <ostream>
#include <array>
#include <string>
#include "Date.h"

const std::array< int, 13 > Date::days =
    {{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }};

Date::Date( int month, int day, int year )
{
    setDate( month, day, year ); 
}

void Date::setDate( int month, int day, int year )
{
    if ( month > 0 && month <= 12 )
        _month = month;
    else
        throw std::invalid_argument("Month must be 1-12");

    if ( year >= 1900 && year <= 2100 )
        _year = year;
    else
        throw std::invalid_argument("Year must be from 1900 to 2100!");

    // test leap and common year
    if ( ( _month == 2 && leapYear( _year ) && day >= 1 && day <= 29 ) || 
         ( day >= 1 && day <= days[ _month ] ) )
        _day = day;
    else 
        throw std::invalid_argument("Day is out of range for current month and year");
}// end function setDate

// Prefix operator: increment date for a day
Date& Date::operator++()
{
    // increment for a day
    _increment();

    // reference return to create lvalue; cascading
    return *this;
}

// Use "dummy parameter" to destinguish between pre- and post- operators
Date Date::operator++( int )
{
    Date temp = *this; // copy operator
    
    _increment();

    // return temporary unchanged date
    return temp;
}

// Add specified number of days
Date& Date::operator+=( int day )
{
    for (int i = 0; i < day; ++i )
        _increment();

    return *this;
}

// Function determines is the year is a leap year
bool Date::leapYear( int year ) const
{
    if ( ( year % 400 == 0 ) || ( year % 100 != 0 && year % 4 == 0 ) )
        return true;
    
    return false;
}

bool Date::endOfMonth( int testDay ) const
{
    // test leap day
    if ( _month == 2 && leapYear( _year ) )
        return ( testDay == 29 );
    
    return ( testDay == days[ _month ] );
}

void Date::_increment()
{
    if ( !endOfMonth( _day )) 
        ++_day;
    else
    {
        if ( _month < 12 )
        {
            ++_month;
            _day = 1;
        }
        else // last day of a year
        {
            ++_year;
            _month = 1;
            _day = 1;
        }
    }
}

std::ostream &operator<<( std::ostream &output, const Date &date )
{
    static std::string monthName[ 13 ] = {
        "",
        "January",
        "Februrary",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    output << monthName[ date._month ] << ' ' << date._day << ", " << date._year;
    
    return output;
}
