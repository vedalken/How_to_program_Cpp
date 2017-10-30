// main.cpp
// Program uses GradeBook class for counting grades.
#include "GradeBook.h"

int main()
{
	GradeBook myGradeBook("Introduction to C++."); // eksplicit constructor call

	// Display welcome message
	myGradeBook.displayMessage();
	
	// Input grades 
	myGradeBook.determineClassAverage();

	// Summary of input grades
	myGradeBook.displayGradeReport();

	return 0;	
}
