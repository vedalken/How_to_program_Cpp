// GradeBook.h
// GradeBook class definition, implementation is in GradeBook.cpp
#include <string>
using std::string;

class GradeBook {
	public:
		GradeBook( string );			// constructor initializes course name
		void setCourseName( string );	// sets course name
		string getCourseName();			// gets course name
		void displayMessage();			// display a welcome message
		void inputGrades();				// input three grades from user
		int	maximum( int, int, int );	// determine maximum integer of 3 values
		void displayGradeReport();		// display grade report based on entered grades
	private:
		string courseName;	// course name
		int maximumGrade;	// maximum grade
};
