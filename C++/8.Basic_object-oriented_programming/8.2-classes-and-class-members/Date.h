// Date.h
// Date class definition.
#ifndef DATE_H
#define DATE_H
class Date
{
public:
	void setDate( int m, int d, int y )
	{ 
		m_nMonth = m;
		m_nDay = d;
		m_nYear = y;
	}
private:
	int m_nMonth;
	int m_nDay;
	int m_nYear;
};
#endif
