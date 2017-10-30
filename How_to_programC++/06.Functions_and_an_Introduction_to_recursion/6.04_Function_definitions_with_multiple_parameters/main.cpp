// main.cpp
// Create GradeBook object, input three grades and display grade report.
#include "GradeBook.h" // class defintion

int main()
{
	GradeBook myGradeBook("Introduction to C++");

	myGradeBook.inputGrades(); // input three grades
	myGradeBook.displayGradeReport(); // display the highest grade entered

	return 0;
}
