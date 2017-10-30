// main.cpp
// Display asteriks diamond. Read integer number fro display dimensions.
#include <iostream>
#include <cmath>	// abs function
// iostream header
using std::cout;
using std::endl;
using std::cin;
// cmath header
using std::abs;

int main()
{
	int n; // diamond dimension (n x n)
	cout << "Enter odd size of asteriks diamond: ";
	cin >> n;

	if (n < 0) // check if number is positive
		n = -n; // change sign of integer number
		
	int tmp; // temporary variable

	for (int i = 1; i <= n; ++i) 
	{
		tmp = abs((n+1)/2 - i );
		// Display spaces
		for (int j = tmp; j > 0; --j)
			cout << " ";
		
		// Display simbols
		for (int k = 0; k < (n-2*tmp); ++k)
			cout << "*";

		cout << endl; // next line
	}

	cout << endl; // new line

	return 0;
}
