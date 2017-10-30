// sum.cpp
// Sum ten numbers.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	// declaration
	int counter;
	unsigned long long sum;

	// initialization
	counter = 1;
	sum		= 0;

	// sum ten numbers
	while (counter <= 1000000000) {
		sum += counter; // sum numbers
		counter++;
	}

	// display information
	cout << "Sum " << sum << endl;

	return 0;	
}
