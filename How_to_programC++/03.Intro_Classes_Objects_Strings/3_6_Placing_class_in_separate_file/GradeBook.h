// GradeBook.h
// Header file for providing class definition - class reusability
#include <iostream>
#include <string>	// program uses C++ standard string class
using namespace std;

// class definition GradeBook
class GradeBook
{
public:
	// constructor initialize courseName with string supplied as arguments
	GradeBook( string name)
	{
		setCourseName( name);
	}

	// function to set course name
	void setCourseName( string name)
	{
		courseName = name;
	}

	// function to get course name
	string getCourseName()
	{
		return courseName; // return object's courseName 
	}
	
	// function displays welcome message and course name to the GradeBook user
	void displayMessage()
	{
		cout << "Welcome to C++ programming\n" << getCourseName() << 
			"!" << endl;
	}

private:
	string courseName;
}; // end class GradeBook

















