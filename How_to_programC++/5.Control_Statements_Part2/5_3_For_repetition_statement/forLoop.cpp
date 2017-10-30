// forLoop.cpp
// Counter controled repetition with the for statement.
#include <iostream>
using std::cout;
using std::endl;

int main()
{	
	// Count from 1 to 10 - display every number
	for (int counter = 1; counter <= 10; ++counter)
		cout << counter << " ";
	
	cout << endl; // new line

	return 0;
}
