// grade_book.cpp
// Create and manipulate GradeBook object; illustrate validation
#include <iostream>
#include "GradeBook.h"
using std::cout;
using std::endl;

// function main begins program execution
int main()
{
	// create Gradebook objects
	GradeBook gradeBook1("Mathematical Physics I");
	// display each GradeBook's course name
	cout << "gradebook1's course name: "	<< gradeBook1.getCourseName() << endl;
	// user enter grades of a course and determine's average grade
	gradeBook1.determineClassAverage();

	return 0;
} // end main
