// grade_book.cppp 
// Program calls object GradeBook() with member function
// displayMessage() for displaying some simple message
#include <iostream>

using namespace std;

// GradeBook class definition used in main
// class contain one member function displayMessage()
// to display message
class GradeBook
{
	// creating public member function - function can 
	// be called by other function
	public:
		// function displays a welcome message to the GradeBook user
		// function does not return any value
		void displayMessage() 
		{
			cout << "Welcome to the Grade Book!" << endl;
		} // end function displayMessage
}; // end class GradeBook

// function main begins program execution
int main()
{
	GradeBook myGradeBook; 		// create a GradeBook object named myGradeBook
	myGradeBook.displayMessage(); 	// call object's displayMessage() function
	
    return 0;
} // end main 
