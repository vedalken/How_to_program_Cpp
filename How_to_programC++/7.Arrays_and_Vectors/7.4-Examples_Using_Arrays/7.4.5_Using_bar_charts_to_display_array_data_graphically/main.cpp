// main.cpp
// Bar chart printing grade distribution.
// Count students with grades 100, and between 90-99, 80-89, etc.
// Number of students are listed in array.
#include <iostream>
#include <iomanip>
using std::cout; // iostream
using std::endl;
using std::setw; //iomanip

int main()
{
	const int arraySize = 11; // array size (10+1) including grade 100
	int array[arraySize] = {0,0,0,0,0,0,1,2,3,2,1};

	for (int i = 0; i < arraySize; ++i)
	{
		if (i == 0) {
			cout << setw(5) << "0-9" << ": ";
		}
		else if (i == 10) {
			cout << setw(5) << "100" << ": ";
		}
		else {
			cout << 10*i << "-" << (10*i + 9) << ": ";
		}

		// display bar chart
		for (int star = 0; star < array[i]; ++star) {
			cout << "*";
		}

		cout << endl; // new line
	}

	return 0;	
}

