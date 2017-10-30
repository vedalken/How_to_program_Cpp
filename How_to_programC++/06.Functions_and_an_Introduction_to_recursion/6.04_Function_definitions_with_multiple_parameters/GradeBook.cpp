// GradeBook.cpp
// GradeBook class implementation. Uses function maximum to determine maximum
// of 3 values. Summary is displayed with function displayGradeReport.
#include <string>
#include <iostream>
#include "GradeBook.h" // class definition
// string header
using std::string;
// iostream header
using std::cout;
using std::endl;
using std::cin;

// Class constructor GradeBook validates and initializes course name and initialize
// maximumGrade
GradeBook::GradeBook( string name ) {
	setCourseName( name ); 	// validate and initialize course name
	maximumGrade = 0;		// this value is replaced by maximum determined value
}

// Function sets course name; limits name to 25 or fewer characters 
void GradeBook::setCourseName( string name ) {
	if (name.length() <= 25) { // limit course name to 25 characters
		courseName = name; // save local value name to private member of GradeBook
	} 
	else {
		// course name has more than 25 characters; set course name to first 25 characters
		courseName = name.substr(0, 25); // select first 25 characters
		cout << "Name \"" << name << " exceeds maximum length (25).\n"
			<< "Limiting course name to first 25 characters.\n" << endl;
	}
}

// Retrieve the course name
string GradeBook::getCourseName() {
	return courseName; // return the course name 
}

// Display a welcome message to the GradeBook user
void GradeBook::displayMessage() {
	// call getCourseName to get the name of course this GradeBook represents
	cout << "Welcome to the grade book for\n" << getCourseName() << "!\n" << endl;
}

// Input three grades from user; determine maximum
void GradeBook::inputGrades() {
	// Read three integer grades
	int grade1;
	int grade2;
	int grade3;

	cout << "Enter three integer grades: ";
	cin >> grade1 >> grade2 >> grade3;

	// Determine maximum and save it to private member maximuGrade
	maximumGrade = maximum( grade1, grade2, grade3 );
}

// Returns maximum of its three integer parameters
int GradeBook::maximum( int x, int y, int z ) {
	int maximumValue = x; // assuming x is maximum value
	
	if ( y > maximumValue ) // compare maximumValue with y
		maximumValue = y; // y is new maximumValue
	
	if ( z > maximumValue ) // compare maximumValue with z
		maximumValue = z; // z is new maximumValue

	return maximumValue; // return maximum value
}		

// Display report based on grades entered by user; display maximum value entered
void GradeBook::displayGradeReport() {
	// Output maximum value entered
	cout << "Highest grade entered: " << maximumGrade << endl;
}


