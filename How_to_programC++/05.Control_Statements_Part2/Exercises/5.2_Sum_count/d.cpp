// d.cpp
// Print five numbers in a row from 1 to 20.
#include <iostream>	// cout
#include <iomanip> 	// setw
using std::cout;
using std::setw;
using std::left;

int main()
{
	int x = 1;

	while (x <= 20) 
	{
		// Display 5 numbers in a row
		if (x % 5 != 0) { 		// print new line
			cout << setw(3) << left << x;
		}
		else {
			cout << setw(3) << left << x << "\n"; 	// display new line 
		}

		++x;
	}

	return 0;
}
