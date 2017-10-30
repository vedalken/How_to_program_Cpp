#ifndef DATE_H
#define DATE_H

class Date
{
public:
	static const int months = 12;
	explicit Date(int year= 1900, int month=1, int day=1);
	void print() const;
	~Date();

private:
	int m_year;
	int m_month;
	int m_day;

	// utility function to check if day is proper for month and year
	int checkDay(int day) const;
};

#endif 
