// GradeBook.cpp
// GradeBook class implementation that solves the class average program
// with sentinel-controlled repetition.
#include <iostream>	// using cin, cout, endl
#include <string>	// using string variables
#include <iomanip>	// for function call setprecision 
using std::cout;
using std::endl;
using std::string;
using std::setprecision;
using std::fixed;

// Constructor - initialize variables
GradeBook::GradeBook( string name ) 
{ 
	setCourseName(name); 
}

// Set course name - validation course name, ensures that course name
// has at most 25 characters
void GradeBook::setCourseName( string name ) 
{
	// If course name has less than or equal 25 characters
	if (name.length() <= 25)
		courseName = name;

	else // if course name is longer than 25 characters
	{
		courseName = name.substr(0,25);	// select first 25 characters, others throw away
		cout << "\nCourse name \"" << name << "\"exceeds maximum number of characters (25).\n" 
			<< "Limiting course name to first 25 characters!" << endl;
	}
}// end setCourseName function

// Get course name 
string GradeBook::getCourseName() 
{ 
	return courseName; 
}

// Display course information
void GradeBook::displayMessage()
{
	cout << "Welcome to grade book for\n" << getCourseName() << "!\n" << endl;
}// end displayMessage function

// Determine class average based on grades entered by user
// Function exits when sentinel value is entered
void GradeBook::determineClassAverage()
{
	int		total;			// total sum of grades
	int		gradeCounter;	// number of entered grades
	int		grade;			// entered grade by user
	double	average;		// average grade of class
	
	// Initialization phase - initialize values to zero
	total			= 0;
	gradeCounter	= 0;

	// Processing phase
	cout << "Enter a grade or -1 to quit: ";
	cin >> grade; // save current grade or sentinel value

	// test for sentinel value or dummy value
	while (grade != -1) 
	{
			total = total + grade;				// sum grades
			gradeCounter = gradeCounter + 1;	// count entered grades

			// prompt user to enter grade
			cout << "Enter a grade or -1 to quit: ";
			cin >> grade;
	}// check for sentinel value in while loop
	
	// At this point, all entered grades are saved or non.
	// Perform analysis report i.e. average class grade
	if (gradeCounter != 0) 
	{ 	// grades were entered, display average class grade
		// calculate average of all entered grades
		average = static_cast<double>( total ) / gradeCounter;

		// display total and average (with two precision)
		cout << "\nTotal of all " << gradeCounter << " grades entered is " 
			<< total << endl;
		// use library iomanip for setprecision function call
		cout << "Class average is " << setprecision( 2 ) << fixed << average << endl;
	}
	else {
		cout << "No grades were entered!." << endl;
	}
}// end determineClassAverage function






