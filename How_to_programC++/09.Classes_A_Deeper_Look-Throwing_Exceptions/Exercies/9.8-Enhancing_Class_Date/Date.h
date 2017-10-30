#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date(int = 1, int = 1, long long int = 2000);
	void setDay(int);
    void setMonth(int);
    void setYear(long long int);

    void nextDay();
	void print() const;

private:
	unsigned int  m_day;
	unsigned int  m_month;
	long long int m_year;
};

#endif
