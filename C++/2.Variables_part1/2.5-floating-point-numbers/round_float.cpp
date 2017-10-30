#include <iostream>

int main()
{
	using namespace std;
	float fValue1 = 1.345f;
	float fValue2 = 1.123f;
	float fTotal = fValue1 + fValue2; 	// should be 2.468

	cout << fValue1 << endl;
	cout << fValue2 << endl;

	if (fTotal == 2.648)
		cout << "fTotal is 2.648" << endl;
	else
		cout << "fTotal is " << fTotal << endl; 
	
	return 0;
}
