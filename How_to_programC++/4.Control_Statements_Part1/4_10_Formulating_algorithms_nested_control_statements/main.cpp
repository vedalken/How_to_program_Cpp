// main.cpp
// Formulating algorithm-nested control-statemnts
// Analyse exam results and decide whether a bonus should
// be paid.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// initilize program execution
int main()
{
	int failed			= 0; // number of students which failed exam
	int passed			= 0; // number of students which passed exam
	int studentCount	= 1; // number of all student who took exam
	int result;				 // exam result (1 passed, 2 failed)

	while (studentCount <= 10)
	{
		// Display message to user
		cout << "Enter a result (1 = passed, 2 = failed): ";
		cin >> result;

		if (result == 1) {
			passed = passed + 1; // count number of students passed exam
		}
		else {
			failed = failed + 1; // count number of students who failed exam
		}

		// count number of students
		studentCount = studentCount + 1;
	}

	// Display a number of passed and failed exam
	cout << "Passed: " << passed << endl;
	cout << "Failed: " << failed << endl;

	// Instructor bonus for more than 8 students passed exam
	if (passed > 8) {
		cout << "Instructor bonus!" << endl;
	}

	return 0;
}// end main
