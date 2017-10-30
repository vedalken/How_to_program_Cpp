// main.cpp
// Sum even numbers.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int total = 0; // initialize total sum
	
	// Sum even numbers
	for (int i = 2; i<10; i += 2) {
		total += i;
	}

	cout << "Sum is " << total << endl;

	return 0;
}
