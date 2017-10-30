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

// calculating average of 10 grades entered by user
void GradeBook::determineClassAverage()
{	
	int gradeCounter; 	// counter of user entered grades
	int totalGrades;	// sum of grades
	// initilaize counter and sum
	gradeCounter = 1;
	totalGrades = 0;
	// current user grade
	int grade;	
	// compute average of 10 grades 
	while (gradeCounter <= 10) 
	{
		// message prompt to a user
		cout << "Enter a grade: ";
		cin >> grade;
		// sum of grades
		totalGrades = totalGrades + grade;
		// increase counter by one
		gradeCounter = gradeCounter + 1; 
	}
	// average of a class is defined as sum of all grades
	// devided by number of grades
	int average;
	// average of 10 grades
	average = totalGrades / 10;

	cout << "\nTotal of 10 grades is "	<< totalGrades
		<< "\nClass average is "		<< average << endl;
 
} // end function determineClassAverage






