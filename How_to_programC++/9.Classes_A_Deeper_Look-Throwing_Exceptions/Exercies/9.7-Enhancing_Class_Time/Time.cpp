#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "Time.h"

// Default and overloaded constructor
Time::Time()
	: Time(0, 0, 0)
{
}

Time::Time(int hour)
	: Time(hour, 0, 0)
{
}

Time::Time(int hour, int minute)
	: Time(hour, minute, 0)
{
}

Time::Time(int hour, int minute, int second)
{
	setTime(hour, minute, second);
}

// set new Time value using universal time
void Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
}

void Time::setHour(int h)
{
	if (h >= 0 && h < 24) {
		m_hour = h;
	}
	else {
		throw std::invalid_argument("hour must be 0-23");
	}
}

void Time::setMinute(int m)
{
	if (m >= 0 && m <= 59) {
		m_minute = m;
	}
	else {
		throw std::invalid_argument("minute must be 0-59");
	}
}

void Time::setSecond(int s)
{
	if (s >= 0 && s <= 59) {
		m_second = s;
	}
	else {
		throw std::invalid_argument("second must be 0-59");
	}
}

// increment time by one tick
void Time::tick()
{
    try {
        // increment a second
        setSecond(m_second + 1);
    }
    catch (const std::invalid_argument &ia_s) {
        try {
            // increment a minute
            setMinute(m_minute + 1);
            // reset time
            setSecond(0);
        }
        catch (const std::invalid_argument &ia_m) {
            try {
                // increment a hour
                setHour(m_hour + 1);
                // reset time
                setMinute(0);
                setSecond(0);
            }
            catch (const std::invalid_argument &ia_h) {
                std::cout << "Invalid hour: " << ia_h.what() << std::endl; 
            }
        }// minute argument
    }// second argument
}// end tick() function

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

