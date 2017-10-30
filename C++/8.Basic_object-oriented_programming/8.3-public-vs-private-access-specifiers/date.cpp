// date.cpp
// Program won't compile!

class Date
{
	// public to access them from other programs
//public:
	// data members have, 
	// class default, access specifier private!
	int m_nMonth;
	int m_nDay;
	int m_nYear;
};

int main()
{
	// Class data members have private access, and
	// cannot be accessed outside of a class!
	Date myDate = { 12, 1, 1783 }; // compile error!

	return 0;	
}
