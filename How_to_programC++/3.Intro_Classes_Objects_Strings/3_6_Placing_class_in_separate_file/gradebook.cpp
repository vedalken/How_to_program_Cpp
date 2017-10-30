// gradebook.cpp
// Define constructor for class GradeBook to initialize and get information 
// on data member via member function setCourseName and getCourseName
// Display total information on course name using another member function
// displayMessage.
#include <iostream>
#include "GradeBook.h" // header file included for class definition 
using namespace std;

// function main begins program execution
int main()
{
	// create two GradeBook objects, with implicit initialization
	GradeBook myGradeBook1( "Mathematical Physics I");
	GradeBook myGradeBook2( "Quantum mechanics");

	// display initial values of courseName for each GradeBook object
	cout << "myGradeBook1 created for course: " << myGradeBook1.getCourseName() <<
		  "\nmyGradeBook2 created for course: "	<< myGradeBook2.getCourseName() <<
		endl;

	return 0;
} // end main

















