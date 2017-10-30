// main.cpp
// Program compute information of student grades of the test:
// minimum and maxium student grade, average, and other stuffs.
#include "GradeBook.h"

int main()
{
	// initialize grades array by the number of students took test
	int arrayGrades[ GradeBook::students ] = 
		{ 87, 68, 94, 100, 83, 78, 85, 91, 76, 87 };
	
	GradeBook myGradeBook( 
		"Introduction to C++ Programming", arrayGrades );

	myGradeBook.displayMessage();
	myGradeBook.processGrades();
	
	return 0;	
}// end main 
