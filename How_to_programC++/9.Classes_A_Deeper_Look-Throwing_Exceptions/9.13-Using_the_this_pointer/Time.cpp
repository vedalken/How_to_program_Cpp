#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h"

Time::Time(int hour, int minute, int second)
{
    setTime(hour, minute, second);
}

Time& Time::setTime(int hour, int minute, int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
    return *this;
}

Time& Time::setHour(int hour)
{
    if (hour >= 0 && hour <= 23) {
        m_hour = hour;
    }
    else {
        throw std::invalid_argument("hour must be 0-23");
    }

    return *this;
}

Time& Time::setMinute(int minute)
{
    if (minute >= 0 && minute < 60) {
        m_minute = minute;
    }
    else {
        throw std::invalid_argument("minute must be 0-59");
    }

    return *this;
}

Time& Time::setSecond(int second)
{
    if (second >= 0 && second < 60) {
        m_second = second;
    }
    else {
        throw std::invalid_argument("second must be 0-59");
    }

    return *this;
}

unsigned int Time::getHour() const
{
    return m_hour;
}

unsigned int Time::getMinute() const
{
    return m_minute;
}

unsigned int Time::getSecond() const
{
    return m_second;
}

void Time::standard() const
{
    std::cout << std::setfill('0') << std::setw(2) << m_hour
        << ":" << std::setw(2) << m_minute 
        << ":" << std::setw(2) << m_second 
        << std::endl;
}

void Time::universal() const
{
    std::cout << ((m_hour == 0 || m_hour == 12) ? 12 : m_hour % 12 )
        << ":" << std::setfill('0') << std::setw(2) << m_minute 
        << ":" << std::setfill('0') << std::setw(2) << m_second
        << (m_hour < 12 ? " AM" : " PM") << std::endl;
}
