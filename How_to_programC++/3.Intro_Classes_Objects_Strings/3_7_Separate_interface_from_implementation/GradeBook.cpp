// GradeBook.cpp
// GradeBook class implementation. This file contains implementation of function
// prototype in GradeBook.h
#include <iostream>
#include "GradeBook.h" // preprocessor copies class definition in this point
using namespace std;

// class GradeBook implementation by calling binary score resolution operator "::"
// othewise member functions would not belong to class GradeBook
// constructor
GradeBook::GradeBook( string name )
{
	setCourseName( name ); // function call sets courseName
}

// member function setCourseName of class GradeBook
// function sets course name
void GradeBook::setCourseName( string name )
{
	courseName = name;
}

// function gets course name 
string GradeBook::getCourseName()
{
	return courseName;
}

// function displays welcome message
void GradeBook::displayMessage()
{
	cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl; 
}
