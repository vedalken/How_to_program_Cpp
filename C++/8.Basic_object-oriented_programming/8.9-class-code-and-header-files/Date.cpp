#include <string>
#include "Date.h"

Date::Date(int day, int month, int year)
{
    SetDate(day, month, year);
}

void Date::SetDate(int day, int month, int year)
{
    m_day   = {day};
    m_month = {month};
    m_year  = {year};
}

std::string Date::GetDate()
{
    std::string ret;
    ret  = std::to_string(m_day)   + "-" +
           std::to_string(m_month) + "-" +
           std::to_string(m_year);
    
    return ret;
}
