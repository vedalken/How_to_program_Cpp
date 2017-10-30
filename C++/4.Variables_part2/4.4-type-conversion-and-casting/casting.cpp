#include <iostream>

int main()
{
	using namespace std;
	
	int nValue1 = 96;
	int nValue2 = 4;
	float fValue1 = (float)nValue1 / nValue2;	// explicit casting
	float fValue2 = float( nValue1 ) / nValue2;	// C style casting, confusing!
	float fValue3 = static_cast<float>( nValue1 ) / nValue2;
	
	cout << "Explicit casting: "	<< fValue1 << endl;
	cout << "C style casting: " 	<< fValue2 << endl;
	cout << "static_cast: " 	<< fValue3 << endl;

	// Tell compiler you are doing something potentially unsafe! 
	char chValue = static_cast<char>(nValue1);	// convert int to char (ASCII code!)
	cout << chValue << endl;

	nValue1 = static_cast<int>(nValue1 / 2.5);
	cout << nValue1 << endl;

	return 0;
}
