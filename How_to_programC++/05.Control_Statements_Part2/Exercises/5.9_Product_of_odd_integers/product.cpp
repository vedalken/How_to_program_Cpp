// product.cpp
// Calculate product of odd integers from 1 to 15.
// Print product result.
#include <iostream>
#include <iomanip>
// iostream header
using std::cout;
using std::endl;
using std::left;
// iomanip header
using std::setw;

int main()
{
	int product = 1;

	// Calculate product of odd integers
	for (int i = 1; i <= 15; i += 2) 
	{
		product *= i;
		// Set width of 8 characters, left alignment
		cout << setw(10) << left << product << endl;
	}

	return 0;	
}
