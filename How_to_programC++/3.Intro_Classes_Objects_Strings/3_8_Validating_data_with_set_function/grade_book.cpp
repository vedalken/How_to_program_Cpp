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
	GradeBook gradeBook1("Introduction to programming in C++ and then with JAVA");
	GradeBook gradeBook2("Mathematical Physics I");

	// display each GradeBook's course name
	cout << "gradebook1's course name: "	<< gradeBook1.getCourseName() 
		<< "\ngradebook2's course name: "	<< gradeBook2.getCourseName() << endl;

	// modify course name
	gradeBook1.setCourseName("Introduction to C++");

	// again display each GradeBook's course name
	cout << "gradebook1's course name: "	<< gradeBook1.getCourseName() 
		<< "\ngradebook2's course name: "	<< gradeBook2.getCourseName() << endl;
	
	return 0;
} // end main
