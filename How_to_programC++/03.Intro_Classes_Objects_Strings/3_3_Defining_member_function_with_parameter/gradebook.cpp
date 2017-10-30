// gradebook.cpp
// Define class GradeBook with member function that has one parameter.
// Called member function display welcome text used by user input.

#include <iostream> // for use cin, cout and endl objects 
#include <string>	// program uses C++ standard string class

using namespace std;

// GradeBook class definition
class GradeBook
{
	public: 
		// function  that displays a welcome  message to the GradeBook user
		void displayMessage( string courseName ) 
		{
			cout << "Welcome to the grade book for\n" << courseName << "!" << endl;
				
		} // end function displayMessage
}; // end GradeBook class

// function main begins program execution
int main()
{
	string nameOfCourse; // string of characters to store name of course
	
	cout << "Please enter course name: " << endl; // prompt for and input course name

	// read line with spaces; when end of line is reached, function exit
	getline( cin, nameOfCourse );
	cout << endl; // new line
	
	GradeBook myGradeBook; // create GradeBook object named myGradeBook

	// call myGradeBook display function displayMessage() and pass
	// nameOfCourse as an argument
	myGradeBook.displayMessage( nameOfCourse );

	return 0;
} // end main
