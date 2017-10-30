// mian.cpp
// Counter-controlled repetition.
#include <iostream>
using std::cout;
using std::endl;

// Program execution begins with main
int main()
{
	int counter = 1; // initialize control variable
	
	// Display numbers from 1 to 10
	while (counter <= 10) 
	{
		cout << counter << " ";
		++counter;
	}

	cout << endl; // new line
	
	// Same proceducre just more concise
	counter = 0; // reinitialize counter variable to one
	
	while (++counter <= 10)
		cout << counter << " ";
	
	cout << endl;
	
	return 0;
} // end main function
