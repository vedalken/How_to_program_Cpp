// grade_book.cpp
// Create and manipulate GradeBook object; illustrate validation
#include <iostream>
#include "GradeBook.h"
using namespace std;

// function main begins program execution
int main()
{
	// create two Gradebook objects
	// initial course name of gradeBook1 is too long
	GradeBook gradeBook1( "How to program C++", "Dietel" );
	GradeBook gradeBook2( "Mathematical Physics I", "Alojz Kodre" );

	// display each GradeBook's course name
	cout << "gradebook1's course name: "	<< gradeBook1.getCourseName()
		<< "\ngradebook2's course name: "	<< gradeBook2.getCourseName() << endl;

	// welcome message
	gradeBook1.displayMessage();
    gradeBook2.displayMessage();

	return 0;
} // end main
