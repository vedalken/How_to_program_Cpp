// GradeBook.h
// GradeBook class definition that determines class average.
// Member functions are defined in GradeBook.cpp
#include <string>	// use string library for standard string manipulation
using std::string;	// get string implementation from standard runtime library 

// class definition
class GradeBook
{
	public: // public member functions are accessible from other functions
		GradeBook( string );				// class constructor-initialization data member
		void	setCourseName(string);		// sets course name
		string	getCourseName();			// gets course name
		void 	displayMessage();			// display information on course name
		void 	determineClassAverage();	// calculate class average grade
		void	inputGrades();				// input grades, count every grade
		void 	displayGradeReport();		// display grade report
	private:
		string courseName;	// name of course
		int aCount;			// count A grades
		int bCount;			// count B grades
		int cCount;			// count C grades
		int dCount;			// count D grades
		int fCount;			// count F grades
}; // end class GradeBook
