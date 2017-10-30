#ifndef DATE_H
#define DATE_H
#include <string>

class Date
{
public:
    Date(int day, int month, int year);
    void SetDate(int day, int month, int year);
    
    std::string GetDate();
    int GetDay() { return m_day; }
    int GetMonth() { return m_month; }
    int GetYear() { return m_year; }

private:
    Date() {} // private default constructor
    int m_day;
    int m_month;
    int m_year;
};

#endif
