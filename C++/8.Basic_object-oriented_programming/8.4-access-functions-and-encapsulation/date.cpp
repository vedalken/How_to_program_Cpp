// date.cpp
// Using class's date setters and getters.
// Set some date using class member function.
#include <iostream>
using std::cout;
using std::endl;

class Date 
{
public:
	//getters
	int getMonth() { return m_nMonth; }
	int getDay() { return m_nDay; }
	int getYear() { return m_nYear; }

	// setters
	void setMonth( int month ) { m_nMonth = month; }
	void setDay( int day ) { m_nDay = day; }
	void setYear( int year ) { m_nYear = year; }

private: // class data members
	int m_nMonth;
	int m_nDay;
	int m_nYear;
};

int main()
{
	Date cMyDate;

	// set some date
	cMyDate.setMonth( 5 );
	cMyDate.setDay( 6 );
	cMyDate.setYear( 1980 );
	
	// display date
	cout << cMyDate.getMonth() << "/" << cMyDate.getDay() 
		<< "/" << cMyDate.getYear() << endl;

	return 0;	
}
