// GradeBook.cpp
// Gradebook class definition presents the public interface of
// the class. Memeber function are implemented in GradeBook.cpp
#include <string>
using namespace std;

// GradeBook class definition
class GradeBook {

	public:
		GradeBook( string name ); 			// constructor that initialize GradeBook
		void setCourseName( string name );	// function sets course name
		string getCourseName();				// funtion gets course name
		void displayMessage();				// function displays welcome message
	private:
		string courseName; // data member course name
}; // end GradeBook class
