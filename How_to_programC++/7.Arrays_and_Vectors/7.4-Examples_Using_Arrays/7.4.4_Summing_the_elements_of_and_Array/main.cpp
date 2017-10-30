// main.cpp
// Sum array elements and display result.
#include <iostream>
using namespace std;

int main()
{
	const int arraySize = 10; // size of array
	int a[arraySize] = {87, 68, 94, 100, 83, 78, 85, 91, 76, 87};
	// total sum of all array elements
	int total = 0;
	
	// sum array elements
	for (int i=0; i < arraySize; ++i)
		total += a[i];

	cout << "Total array sum: " << total << endl;

	return 0;	
}
