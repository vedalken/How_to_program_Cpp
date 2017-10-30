// gradebook.cpp
// Class GradeBook has data member courseName, and three member functions setCourseName,
// getCourseName and displayMessage.
// Using these functions, user can set course name my calling member function of a class,
// and get information on course name. Indirectly data member can change value.
#include <iostream>
#include <string>   // program uses standard C++ string class
using namespace std;

// GradeBook class definition
class GradeBook
{
    public:
        // function sets course name
        void setCourseName( string name )
        {
            courseName = name; // set course name
        }

        // function gets course name
        string getCourseName()
        {
            return courseName;
        }

        // function that displays a welcome message
        void displayMessage()
        {
            // this statements calls getCourseName function within class GradeBook
            cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
        }
    private: 				// accessible only within GradeBook
        string courseName;	// course name for GradeBook; data member

}; // end class GradeBook

// function main begins program execution
int main()
{
	cout << "Welcome to C++ programming\n";
	
	GradeBook myGradeBook;
	// output should be empty; no initial value is used
	cout << myGradeBook.getCourseName() << endl;
	
	string nameOfCourse; 						// string of characters to store course name
	cout << "\nPlease enter course name: "; 	// prompt for input (set) course name
	getline( cin, nameOfCourse );				// read course name with blanks
	myGradeBook.setCourseName( nameOfCourse );	// set course name
	
	cout << endl; // new line
	myGradeBook.displayMessage();				// display welcome message

	return 0;	
} // end main function













