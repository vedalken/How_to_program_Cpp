// continue.cpp
// Execute continue statement for terminating for loop.
// Program prints numbers from 1 to 10, skipping 5.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int count; // count numbers
	
	for (count = 1; count <= 10; ++count) 
	{
		if (count == 5) { // skip number 5
			continue;
		}

		cout << count << " ";
	}
	
	cout << "\nNumber 5 is skipped." << endl;

	return 0;
}
