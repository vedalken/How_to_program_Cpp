// GradeBook.h
// Class GradeBook declaration.
// Class uses two dimensional arrays to store for each
// student, grades which took e.g. per semester
// Class displays maximum and minimum grade student achived,
// average grade per student, and grade distribution bar chart.
#ifndef GRADEBOOK_H
#define GRADEBOOK_H
#include <string>
using std::string;

class GradeBook 
{
public:
	static const int m_nNumStudents = 10;	// number of students
	static const int m_nNumTests = 3; 		// number of test each student took one semester
	
	// GradeBook constructor initializes course name and
	// array of grades
	GradeBook(); 									  // default constructor
	GradeBook( string, const int [][ m_nNumTests ] ); // class constructor
	
	void setCourseName( string );	// set course name
	string getCourseName();			// get course name
	void displayMessage();			// display welcome message
	void processGrades();			// perform various operation on grade book data
	int getMinimum();				// find minimum grade in grade book
	int getMaximum();				// find maximum grade in grade book
	double getAverage( const int [], const int ); // get student's average
	void outputGrades();			// output two dimensional grades array
	void outputBarChart(); 			// output grade distribution
private:
	// course name (member of a class m_)
	string m_strCourseName; 

	// two dimensional array of grades each student took e.g. 
	// on semester
	int m_anGrades[ m_nNumStudents ][ m_nNumTests ];
};
//end GradeBook class declaration

#endif // end GRADEBOOK_H header guard
