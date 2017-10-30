// gradebook.cpp
// GradeBook class demonstration after separating its interface
// from its implementation
#include <iostream>
#include "GradeBook.h" // including class GradeBook definition
using namespace std;

// program execution begins with main
int main()
{
	// create two objects with implicit initialization courseName
	// by calling constructor
	GradeBook myGradeBook1("Mathematical Physics I");
	GradeBook myGradeBook2("Statistical Physics");
	
	// display initial values of courseName for each GradeBook object
	cout << "myGradeBook1 created for course: " << myGradeBook1.getCourseName() <<
		"\nmyGradeBook2 created for course: " 	<< myGradeBook2.getCourseName() << 
		endl;

	return 0;	
} // end main
