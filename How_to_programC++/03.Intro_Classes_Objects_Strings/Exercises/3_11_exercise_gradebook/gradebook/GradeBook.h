// GradeBook.cpp
// Gradebook class definition presents the public interface of
// the class. Memeber function are implemented in GradeBook.cpp
#include <string>
using namespace std;

// GradeBook class definition
class GradeBook
{
	public:
        // constructor that initialize GradeBook
		GradeBook (string name, string instructor);
		// function sets course name
		void setCourseName (string name);
		// sets course instructor's name
		void setInstructorName (string instructor);
		// funtion gets course name
		string getCourseName();
		// gets course instructor's name
		string getInstructorName();
		// function displays welcome message
		void displayMessage();
	private:
		string courseName;              // data member course name
		string courseInstructorName;    // course instructor's name
}; // end GradeBook class
