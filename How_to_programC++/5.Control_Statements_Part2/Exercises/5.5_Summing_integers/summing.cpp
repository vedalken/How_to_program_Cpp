// summing.cpp
// Summing integer values. Number of sumed values is entered by user
// and every sumed value is read.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	// Enter integers separting with new lines or spaces or tabs
	int n = 0; 	// number of integer values to read
	cin >> n;	// cin ignores new lines, spaces and tabs!

	int sum = 0; // initial sum value

	// Input integer numbers and sum them
	for (int i = n; i > 0; --i)
	{
		int number;
		cin >> number;
		// sum entered integers
		sum += number;
	}// destroy i, number

	// Output sum 
	cout << "Sum is: " << sum << endl;

	return 0;
}
