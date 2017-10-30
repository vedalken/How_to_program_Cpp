// main.cpp
// Program uses two dimensional array for storing 
// for each student all grades in one semester.
#include "GradeBook.h"

int main()
{
	// each column represent student grades 
	int anGradesArray[ GradeBook::m_nNumStudents ][ GradeBook::m_nNumTests ] =
		{ { 78, 96, 70 },
		  { 68, 87, 90 },
		  { 95, 100, 92 },
		  { 100, 81, 83 },
		  { 61, 95, 89 },
		  { 82, 54, 76 },
		  { 85, 75, 83 },
		  { 91, 94, 100 },
		  { 66, 62, 75 },
		  { 72, 75, 86 }
		};

	GradeBook cMyGradeBook( "C++ Programming", anGradesArray );
	
	cMyGradeBook.displayMessage();
	cMyGradeBook.processGrades(); 

	return 0;	
}
