// GradeBook.cpp
// GradeBook class implementation that solves the class average program
// with sentinel-controlled repetition.
#include <iostream>	// using cin, cout, endl
#include <string>	// using string variables
#include <iomanip>	// for function call setprecision 
#include <cstdio>	// for EOF macro
#include "GradeBook.h"

// iostream header
using std::cout;
using std::endl;
using std::cin;
// string header
using std::string;
// iomanip header
using std::setprecision;
using std::fixed;

// Constructor - initialize variables
GradeBook::GradeBook( string name ) 
{ 
	setCourseName(name); 

	// Initialize grade counters
	aCount = 0; // set grade A counter to 0 
	bCount = 0; // set grade B counter to 0
	cCount = 0; // set grade C counter to 0
	dCount = 0; // set grade D counter to 0
	fCount = 0; // set grade F counter to 0
}// end constructor

// Set course name - validation course name, ensures that course name
// has at most 25 characters
void GradeBook::setCourseName( string name ) 
{	// If course name has less than or equal 25 characters
	if (name.length() <= 25) 
	{
		courseName = name;
	}
	else  // if course name is longer than 25 characters
	{
		courseName = name.substr(0,25);	// select first 25 characters, others throw away
		cout << "\nCourse name \"" << name << "\"exceeds maximum number of characters (25).\n" <<
			 "Limiting course name to first 25 characters!" << endl;
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
	int total;			// total sum of grades
	int	gradeCounter;	// number of entered grades
	
	// Initialization phase - initialize values to zero
	total			= 0;
	gradeCounter	= 0;

	// Processing phase
	cout << "Enter a latter grades (EOF to quit: <Ctrl>+d): ";
	char latterGrade;	// entered grade by user

	// test for sentinel value or dummy value
	while ( (latterGrade = cin.get()) != EOF) 
	{	
		int grade; // local grade numbering

		switch (latterGrade)
		{	case 'A':
			case 'a': grade = 4; 
						aCount++; // count A grades
						break;
			case 'B':
			case 'b': grade = 3; 
						bCount++; // count B grades
						break;

			case 'C':
			case 'c': grade = 2; 
						cCount++; // count C grades
						break;

			case 'D':
			case 'd': grade = 1; 
						dCount++; // count D grades
						break;
			
			case 'F':
			case 'f': grade = 0; 
						fCount++; // count F grades
						break;
			
			default: continue; // read next character, skip total
		}

		total += grade;	// sum grades
		gradeCounter++;
	}// check for sentinel value in while loop
	
	double	average;		// average grade of class
	
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
	else 
	{
		cout << "No grades were entered!." << endl;
	}

}// end determineClassAverage function


// Input letter grades
void GradeBook::inputGrades()
{
	int grade; // current grade

	cout << "Enter letter grades. " << endl
		<< "Enter the EOF character to end input." << endl;
	// Read a grade (character) until EOF is pressed (Ctrl+d)
	// Input character is implicitly converted to integer number
	while ( (grade = cin.get()) != EOF ) 
	{
		switch (grade) // const characters are converted to integers 
		{	// Read correct grades
			case 'A':
			case 'a':	++aCount;
						break;
			case 'B':
			case 'b': 	++bCount;
						break;
			case 'C':
			case 'c':	++cCount;
						break;
			case 'D':
			case 'd': 	++dCount;
						break;
			case 'F':
			case 'f':	++fCount;
						break;
			
			// Ignore newlines, tabs, and spaces in input
			case '\n':
			case '\t':
			case ' ':	break;

			// Catch all other characters
			default:
					cout << "Incorrect letter grade entered."
						<< "Enter new grade." << endl;
		}// end switch statement		
	}// end while loop
}// end function inputGrades


// Display grades report based on user input
void GradeBook::displayGradeReport()
{	
	// Print summary of results
	cout << "\n\nNumber of students who received each grade:"
		<< "\nA: " << aCount
		<< "\nB: " << bCount
		<< "\nC: " << cCount
		<< "\nD: " << dCount
		<< "\nF: " << fCount 
		<< endl;
}// end displayInputGrades function




