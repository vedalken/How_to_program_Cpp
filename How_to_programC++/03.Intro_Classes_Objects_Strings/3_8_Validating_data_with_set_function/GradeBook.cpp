// GradeBook.cpp
// GradeBook class implemente defined member-functions.
// The getCourseName function performs validation.
#include <iostream>
#include "GradeBook.h" // header file with class definition
using namespace std;

// constructor initializes courseName with string supplied as argument 
GradeBook::GradeBook(string name)
{
	setCourseName(name);
}

// function that sets courseName
// ensure validation of course name at most 25 characters
void GradeBook::setCourseName(string name)
{
	// if course name has 25 or less characters, store to courseName
	if (name.length() <= 25) 
		courseName = name;
	
	// if course name has more than 25 characters, perform validation
	if (name.length() > 25) 
	{
		// set course name to first 25 characters
		courseName = name.substr(0,25); // start at 0, length of 25

		cout << "Name \"" << name << "\" exceeds maximum length (25).\n"
			<< "Limiting course name to first 25 characters." << endl;
	}
}

// function gets course name
string GradeBook::getCourseName()
{
	return courseName; // return object's courseName
}

// function displays welcome message
void GradeBook::displayMessage()
{
	cout << "Welcome to the grade book for \n" << getCourseName() << "!" << endl;
}
