// GradeBook.cpp
// Class GradeBook implementation that uses array
// to store grades.
#include <iostream>
#include <iomanip>
#include <string>
#include "GradeBook.h" // class GradeBook definition
using std::cout; // iostream header
using std::endl;
using std::fixed;
using std::setw; // iomanip header
using std::setprecision;
using std::string; // string header

// GradeBook constructor initializes course name and grades array
GradeBook::GradeBook( string nameOfCourse, const int gradesArray[] ) 
{
	setCourseName( nameOfCourse ); // set course name
	
	// copy grades from gradesArray to grades
	for ( int i = 0; i < students; ++i ) {
		grades[i] = gradesArray[i];
	}
}//end GradeBook constructor

// set course name
void GradeBook::setCourseName( string nameOfCourse ) 
{
	courseName = nameOfCourse;
}

// retrieve course name
string GradeBook::getCourseName() 
{
	return courseName;
}

// display a welcome message to the GradeBook user
void GradeBook::displayMessage()
{
	cout << "Welcome to the grade book for\n" << getCourseName()
		<< "!" << endl;
}

// find the maximum grade for the test
int GradeBook::getMaximum()
{
	// initialize maximum grade to the minimum value
	int highGrade = 0; 

	for ( int student = 0; student < students; ++student )
	{
		// find maximum grade
		if ( grades[ student ] > highGrade ) {
			highGrade = grades[ student ]; // current maximum grade
		}
	}

	return highGrade; // return highest grade
}// end getMaximum function

// find the minimum grade for the test
int GradeBook::getMinimum()
{
	// initialize minimum grade to the maximum value
	int lowGrade = 100;

	for ( int student = 0; student < students; ++student )
	{	
		// find the smallest grade
		if ( grades[ student ] < lowGrade ) {
			lowGrade = grades[ student ];
		}
	}// end for loop

	// return the smallest grade for the test
	return lowGrade; 
}// end getMinimum function

// calculate average test grade
double GradeBook::getAverage()
{
	int sumOfGrades = 0; // sum of grades

	// sum grades
	for ( int student = 0; student < students; ++student )
		sumOfGrades += grades[ student ];
	
	// average test grade
	double averageGrade = 0.;
	averageGrade = static_cast<double>( sumOfGrades ) / students;
	
	return averageGrade;
}// end getAverage function

// output grades of the test
void GradeBook::outputGrades()
{
	cout << "\nThe grades are:\n\n";

	for ( int i = 0; i < students; ++i )
		cout << "Student " << (i + 1) << ":" << setw(5) << grades[ i ] << endl;
	
}// end outputGrades

// output bar chart displaying grade distribution
void GradeBook::outputBarChart()
{
	// store frequency of grades in each range 
	// (0-9, 10-19,..., 90-99, 100)
	const int frequencySize = 11;	
	int frequency[ frequencySize ] = {}; // initialize to 0

	// count grade frequency
	for ( int i = 0; i < students; ++i )
		++frequency[ grades[ i ] / (frequencySize - 1) ];
	
	// for each grade frequency print bar of asterisks
	for ( int count = 0; count < frequencySize; ++count )
	{
		if ( count == 0 ) 
			cout << setw(7) << "0-9: ";
		else if ( count == 10 ) 
			cout << setw(7) << "100: ";
		else 
			cout << 10*count << "-" << 10*(count + 1) - 1 << ": "; 

		// print bar of asterisks
		for ( int j = 0; j < frequency[ count ]; ++j )
			cout << "*";
		
		cout << endl; // start a new line
	}// end for loop
}// end outputBarChart function

// perform various operation on the grades
void GradeBook::processGrades()
{
	outputGrades(); // output grades array
	
	// display average, min and max grades
	cout << setprecision(2) << fixed << "\nClass average: " << getAverage()
		<< "\nLowest grade: " << getMinimum()
		<< "\nHighest grade: " << getMaximum() << endl;

	outputBarChart(); // print grade distribution chart
}// end processGrades
