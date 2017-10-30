// gradebook.cpp
// Define constructor for class GradeBook to initialize and get information 
// on data member via member function setCourseName and getCourseName
// Display total information on course name using another member function
// displayMessage.
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

// function main begins program execution
int main()
{
	// create two GradeBook objects, with implicit initialization
	GradeBook myGradeBook1( "Mathematical Physics I");
	GradeBook myGradeBook2( "Quantum mechanics");

	// display initial values of courseName for each GradeBook object
	cout << "myGradeBook1 created for course: " << myGradeBook1.getCourseName() <<
		  "\nmyGradeBook2 created for course: "	<< myGradeBook2.getCourseName() <<
		endl;

	return 0;
} // end main

















