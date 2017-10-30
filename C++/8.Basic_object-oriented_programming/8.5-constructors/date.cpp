// date.cpp
// Date class uses default construcotr parameter
// list to instalize member variables.
class Date
{
public:
	// Date class constructor
	Date( int month=1, int day=1, int year=1990 )
	{
		m_nMonth = month;
		m_nDay = day;
		m_nYear = year;
	}
private:
	int m_nMonth;
	int m_nDay;
	int m_nYear;
};

int main()
{
	Date cDate; // initialized to default date 1/1/1990

	Date cToday( 8, 5, 2007); // initialized to some day
	
	return 0;	
}
