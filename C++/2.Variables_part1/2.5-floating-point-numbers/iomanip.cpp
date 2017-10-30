#include <iostream>
#include <iomanip>	// for setprecision()

int main()
{
	using namespace std;

	cout << setprecision(16);	// show 16 digits
	float fValue = 3.333333333333333333333333333333333333;
	cout << fValue << endl;
	double dValue = 3.333333333333333333333333333333333333;
	cout << dValue << endl;
	
	return 0;
}
