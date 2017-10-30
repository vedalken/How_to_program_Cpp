// main.cpp
// Round numbers to the nearest integer number using floor( x + 0.5 )
#include <iostream> // cin, cout, endl
#include <cstdio>   // EOF 
#include <iomanip>  // setw
#include <cmath>
using namespace std;

int main()
{
	float x; // number entered by user

	cout << "Program rounds up to the nearest integer (Ctrl-d to exit).\n";
	cout << "Enter floating-point number: ";
	cin >> x;

	// Display rounded numbers
	while (1) {
		cout << x << setw(5) << floor( x + 0.5 ) << endl;
		cout << "Enter floating-point number: ";
		cin >> x;
	}

	return 0;	
}
