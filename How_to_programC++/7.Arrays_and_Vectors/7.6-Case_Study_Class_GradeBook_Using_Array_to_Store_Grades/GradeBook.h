// GradeBook.h
// Definition of class GradeBook that uses array to store
// test grades. Member functions are defined in GradeBook.cpp.
#include <string>
using std::string;

class GradeBook 
{
public:
	// number of students took test
	static const int students = 10;

	// constructor initializes course name and array of grades
	GradeBook( string, const int [] );
	
	void setCourseName( string );	// set course name 
	string getCourseName();			// retrieve course name
	void displayMessage();			// display a welcome message
	int getMaximum();				// find the maximum grade for the test
	int getMinimum();				// find the minimum grade for the test
	double getAverage();			// calculate average test grade
	void outputGrades();			// output grades of the test
	void outputBarChart();			// output bar char displaying grade distribution
	void processGrades();			// perform various operations on the grade data
private:
	string courseName; 		// course name for this grade book
	int grades[ students ]; // array of student grades
};
