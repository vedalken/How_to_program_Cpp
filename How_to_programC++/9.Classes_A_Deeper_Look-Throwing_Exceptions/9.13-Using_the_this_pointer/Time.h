#ifndef TIME_H
#define TIME_H

class Time
{
public:
    explicit Time(int = 0, int = 0, int = 0);
    
    // set functions
    Time& setTime(int, int, int);
    Time& setHour(int);
    Time& setMinute(int);
    Time& setSecond(int);

    // get functions
    unsigned int getHour() const;
    unsigned int getMinute() const;
    unsigned int getSecond() const;

    // print time
    void standard() const;
    void universal() const;

private:
    unsigned int m_hour;   // 0 - 23 (24-hour clock system)
    unsigned int m_minute; // 0 - 59
    unsigned int m_second; // 0 - 59
};

#endif
