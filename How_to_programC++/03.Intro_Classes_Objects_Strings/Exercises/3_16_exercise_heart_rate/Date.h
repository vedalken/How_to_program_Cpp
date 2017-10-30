// Date.h
// Header used for definition of Date class

// class Date declaration
class Date
{
	public:
		// constructor class Date; initialize data members in same order
		Date(int, int, int);
		// set and get function for month
		void setMonth(int);
		int getMonth();
		// set and get function for day
		void setDay(int);
		int getDay();
		// set and get function for year
		void setYear(int);
		int getYear();
		// display date
		void displayDate();
		
	private: // Date class data members 
		int month;
		int day;
		int year;
};// end class


