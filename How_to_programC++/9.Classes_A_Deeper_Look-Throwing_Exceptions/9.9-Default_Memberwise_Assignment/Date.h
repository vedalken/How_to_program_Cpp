#ifndef DATE_H
#define DATE_H

class Date
{
public:
	explicit Date(int = 1, int = 1, int = 2000);
	void print() const;
	void setDay(int);

private:
	unsigned int m_day;
	unsigned int m_month;
	unsigned int m_year;
};

#endif
