#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "Time.h"

Time::Time()
	: m_hour(0), m_minute(0), m_second()
{
	// nothing to do
}

// set new Time value using universal time
void Time::setTime(int h, int m, int s)
{
	if ((h >= 0 && h <= 24) & (m >= 0 && m <= 60) &
		(s >= 0 && s <= 60)) 
	{
		m_hour   = h;
		m_minute = m;
		m_second = s;
	}
	else {
		throw std::invalid_argument(
				"hour, minute and/or second was out of range");
	}
}

// poor practic: returning a reference to a private data member
unsigned int& Time::badSetHour(int h)
{
	if (h >= 0 && h < 24) {
		m_hour = h;
	}
	else {
		throw std::invalid_argument("hour must be 0-23");
	}

	return m_hour; // dangerous reference return
}

// print Time in universal-time format
void Time::printUniversal() const 
{
	std::cout << std::setfill('0') 
		<< std::setw(2) << m_hour   << ":" 
		<< std::setw(2) << m_minute << ":"
		<< std::setw(2) << m_second << std::endl;
}

// print Time in standard-time format
void Time::printStandard() const
{
	std::cout << std::setfill('0')
		<< std::setw(2) << ((m_hour == 0 || m_hour == 12) ? 12 : m_hour % 12) << ":"
		<< std::setw(2) << m_minute << ":"
		<< std::setw(2) << m_second << " "
		<< (m_hour > 12 ? "PM" : "AM") << std::endl;
}
