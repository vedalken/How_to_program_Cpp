// factorial.cpp
// Calculate factorial of small integers (from 1 to 5).
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n; // calculate n!
	cin >> n;
	
	// Calculate factorial from last number until count number
	// reaches 1
	int factorial = 1;
	for (int i=n; i>0; --i)
		factorial *= i; 
	
	cout << "\n" << n << "! = " << factorial << endl;

	return 0;	
}
