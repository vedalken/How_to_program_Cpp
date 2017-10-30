// GradeBook.cpp
// GradeBook class implementation.
#include <iostream>
#include <string>
#include <iomanip>
#include "GradeBook.h"
using std::cout;	// iostream header
using std::endl;
using std::fixed;
using std::string;	// string header
using std::setw; 	// iomanip header
using std::setprecision;

// default constructor initialize course name, and
// grade array to 0
GradeBook::GradeBook()
{
	setCourseName( "No course name set" );

	// default array initialization
	for ( int nStudent = 0; nStudent < m_nNumStudents; ++nStudent )
	{	
		for ( int nTest = 0; nTest < m_nNumTests; ++nTest )
			m_anGrades[ nStudent ][ nTest ] = 0;
	}

}//end GradeBook constructor

// constructor with parameters
GradeBook::GradeBook( string strCourseName, const int anGradesArray[][ m_nNumTests ] )
{
	setCourseName( strCourseName ); // set course name

	// initialize class array of grades
	for ( int nStudent = 0; nStudent < m_nNumStudents; ++nStudent )
	{	
		for ( int nTest = 0; nTest < m_nNumTests; ++nTest )
			m_anGrades[ nStudent ][ nTest ] = anGradesArray[ nStudent ][ nTest ];
	}
}// end GradeBook constructor with parameters

// set course name
void GradeBook::setCourseName( string strCourseName ) { 
	m_strCourseName = strCourseName; 
}

// get course name
string GradeBook::getCourseName() { 
	return m_strCourseName; 
}

// display welcome message
void GradeBook::displayMessage()
{
	cout << "\nWelcome to the grade book " << getCourseName() << "!"
		<< endl;
}

// display grade book grades, calculate min and max grade
// and display bar chart
void GradeBook::processGrades()
{
	outputGrades(); // display grades
	
	// display smallest and highest grade
	cout << "\nLowest grade: " << getMinimum()
		<< "\nHighest grade: " << getMaximum() << endl;
	
	outputBarChart(); // print grade distribution
}// end processGrades function

// determine minimum grade in the grade book
int GradeBook::getMinimum()
{
	// minimum grade
	int nMinGrade = 100; // initialize minimum grade to maximum value
	
	// find minimum grade
	for ( int nStudent = 0; nStudent < m_nNumStudents; ++nStudent )
	{	
		for ( int nTest = 0; nTest < m_nNumTests; ++nTest )
		{
			if ( m_anGrades[ nStudent ][ nTest ] < nMinGrade )
				nMinGrade = m_anGrades[ nStudent ][ nTest ]; // current minimum grade
		}
	}
	
	return nMinGrade; // return minimum grade
}//end getMinumum function

// determine maxiumum grade
int GradeBook::getMaximum()
{
	// maximum grade is initialized to smallest grade
	int nMaxGrade = 0;	
	
	// find maximum grade
	for ( int nStudent = 0; nStudent < m_nNumStudents; ++nStudent )
	{	
		for ( int nTest = 0; nTest < m_nNumTests; ++nTest )
		{
			if ( m_anGrades[ nStudent ][ nTest ] > nMaxGrade )
				nMaxGrade = m_anGrades[ nStudent ][ nTest ]; // current maximum grade
		}
	}// end outer for loop

	return nMaxGrade; // return maximum grade
}// end getMaximum function

// calculate average grade
double GradeBook::getAverage( const int anArrayGrades[], const int nArraySize )
{
	int nTotalGrades = 0; // sum of grades

	for ( int nGrade = 0; nGrade < nArraySize; ++nGrade )
		nTotalGrades += anArrayGrades[ nGrade ]; 

	// return average grade
	return ( static_cast<double>( nTotalGrades ) / nArraySize );
}//end getAverage function

// output 2D array of students grades
// columns represent tests grades per student,
// while row represent student number
// last column represents student's average grade
void GradeBook::outputGrades()
{
	cout << "\nThe grades are:\n";

	// display columns
	cout << setw(10) << " "; // shift 10 chars

	// display number of tests
	for ( int nTest = 0; nTest < m_nNumTests; ++nTest )
		cout << setw(10) << "Test" << setw(2) << nTest + 1;
	
	cout << setw(12) << "Average" << endl; // new line
	
	// display grades for each student
	for ( int nStudent = 0; nStudent < m_nNumStudents; ++nStudent )
	{
		cout << setw(7) << "Student" << setw(3) << nStudent + 1;
		
		for( int nTest = 0; nTest < m_nNumTests; ++nTest )
			cout << setw(12) << m_anGrades[ nStudent ][ nTest ];

		// last column: student's average
		cout << setw(12) << setprecision(2) << fixed 
			<< getAverage( m_anGrades[ nStudent ],  m_nNumTests ) 
			<< endl; // new line
	}
}// end outputGrades function

// output bar chart displaying grade distribution
void GradeBook::outputBarChart()
{
	cout << "\nOverall grade distribution:" << endl;

	const int nFrequencySize = 11; 			// 0-9,10-11,...,90-99,100
	int anFrequency[ nFrequencySize ] = {}; // initialize to 0
	
	// count frequency grades
	for ( int nStudent = 0; nStudent < m_nNumStudents; ++nStudent )
	{
		for ( int nTest = 0; nTest < m_nNumTests; ++nTest )
		{
			// count frequency of grades
			// each grade divide by 10 ( integer division! )
			++anFrequency[ m_anGrades[ nStudent ][ nTest ] / 10 ];
		}
	}
	
	// display grades distribution
	for ( int nCount = 0; nCount < nFrequencySize; ++nCount )
	{
		if ( nCount == 0 )
			cout << setw(6) << "0-9:" << " ";
		else if ( nCount == 10 )
			cout << setw(6) << "100:" << " ";
		else
			cout << nCount*10 << "-" << ( nCount*10 + 9 ) << ":" << " ";

		// print asterisks bar
		for ( int nAsterisk = 0; nAsterisk < anFrequency[ nCount ]; ++nAsterisk )
			cout << "*";

		cout << endl; // new line
	}
}// end outputBarChart function
