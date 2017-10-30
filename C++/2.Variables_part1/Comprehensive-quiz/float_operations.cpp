// Program compute mathematical operation
// on two floating numbers.
#include <iostream>
#include <iomanip>		// used for setpresicion()

int main()
{
	using namespace std;
	
	cout << setprecision(6);

	cout << "Enter a value: ";
	float fValue1;
	cin >> fValue1;
	
	cout << "Enter second value: ";
	float fValue2;
	cin >> fValue2;

	cout << "Choose mathematical operation(+,-,* or /): ";
	char chMathOperator;
	cin >> chMathOperator;

	cout << endl;
	cout << fValue1 << chMathOperator << fValue2 <<" = ";
	
	float fResult;
	if (chMathOperator == '+') 
	{
		fResult = fValue1 + fValue2;
		cout << fResult << endl;
	}
	else if (chMathOperator == '-') 
	{
		fResult = fValue1 - fValue2;
		cout << fResult << endl;
	}
	else if (chMathOperator == '*')
	{
		fResult = fValue1 * fValue2;
		cout << fResult << endl;
	}
	else if (chMathOperator == '/')
	{
		fResult = fValue1 / fValue2;
		cout << fResult << endl;
	}
	else 
	
	cout << endl;

	return 0;		
}
