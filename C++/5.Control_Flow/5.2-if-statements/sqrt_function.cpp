#include <iostream>
#include <cmath> // for sqrt function call

void PrintSqrt(double dValue)
{
	using namespace std;

	if (dValue >= 0.0)
		cout << "Square root of " << dValue << " = " << sqrt(dValue) << endl;
	else
		cout << "Error: " << dValue << " is negative" << endl; 
}

int main()
{
	using namespace std;

	cout << "Enter a number: ";
	double dNumber;
	cin >> dNumber;

	PrintSqrt(dNumber);

	return 0;
}
