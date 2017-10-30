// main.cpp
// Program displays base 10 table of some numbers i.e.
// N=1 10	100	1000
// N=2 20	200	2000 
// etc.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int	base;
	cout << "Enter base (e.g. binary 2, base 10): ";
	cin >> base;

	int number;
	cout << "Enter number of rows: ";
	cin >> number;

	// Table output 
	cout << "N" << "\tN*base" << "\tN*base^2" << "\tN*base^3" << endl;

	int counter = 1; // initialize counter

	// Display table of number of numbers
	while (counter <= number)
	{
		cout << counter << "\t" << base*counter << "\t" << base*base*counter 
			<< "\t\t" << base*base*base*counter << endl;

		// increment counter
		++counter;
	}

	return 0;
}
