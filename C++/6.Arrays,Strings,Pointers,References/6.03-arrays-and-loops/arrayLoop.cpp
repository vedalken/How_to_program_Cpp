// arrayLoop.cpp
// Calculate average students score using array.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// total number of students
	const int nNumberOfStudents = 5;
	// score of each student
	int anScore[ nNumberOfStudents ] = { 84, 92, 76, 81, 56 };
	// total score of all students
	int nTotalScore = 0;
	
	for (int nStudent = 0; nStudent < nNumberOfStudents; ++nStudent)
		nTotalScore += anScore[ nStudent ];
	
	// calculate average score
	double dAverageScore;
	dAverageScore = static_cast<double>( nTotalScore ) / nNumberOfStudents;

	cout << "Number of students: " << nNumberOfStudents << endl;
	cout << "Total score: " << nTotalScore << endl;
	cout << "Average score: " << dAverageScore << endl;

	return 0;	
}
