#ifndef TIME_H
#define TIME_H

class Time
{
public:
	Time();
	void setTime(int hour, int m_minute, int second);
	void printUniversal() const;
	void printStandard() const;
private:
	unsigned int m_hour;
	unsigned int m_minute;
	unsigned int m_second;
};

#endif
