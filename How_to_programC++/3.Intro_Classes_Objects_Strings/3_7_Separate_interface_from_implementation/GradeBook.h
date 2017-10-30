// GradeBook.h 
// GradeBook class definition. This file presents public class interface
// without revealing the implementation of member function, which are
// defined in GradeBook.cpp
#include <string>		// program uses C++ standard string class
using namespace std;

// definition of class GradeBook; with function prototype
class GradeBook 
{
public:
	GradeBook( string name );			// constructor initializes courseName
	void setCourseName( string name );	// function sets the course name
	string getCourseName();				// function gets the course name
	void displayMessage();				// function displays a welcome message
private:
	string courseName;
}; // end class GradeBook
