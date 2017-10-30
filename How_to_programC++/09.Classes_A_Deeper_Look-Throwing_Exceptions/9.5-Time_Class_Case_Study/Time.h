#ifndef TIME_H
#define TIME_H

class Time
{
public:
	// Default constructor
	explicit Time();
	explicit Time(int hour);
	explicit Time(int hour, int minute);
	Time(int hour, int minute, int second);

	// Mutators
	void setTime(int hour, int m_minute, int second);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);

	// Accessors
	unsigned int getHour()   const { return m_hour; }
	unsigned int getMinute() const { return m_minute; }
	unsigned int getSecond() const { return m_second; }

	// Print Time
	void printUniversal() const;
	void printStandard() const;
private:
	unsigned int m_hour;
	unsigned int m_minute;
	unsigned int m_second;
};

#endif
