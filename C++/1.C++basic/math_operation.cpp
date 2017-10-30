// Program compute two integer numbers using mathematical
// operation(+,-,* or. /) chosen by a user.
#include <iostream>
#include <string>
using namespace std;

// function prototype
int  GetUserInput ();
char GetMathOperation ();
int  CalculateResult (int fistn, char choper, int secondn);
void PrintResult (int nResult);

int main()
{
	// Get first number from user
	int n1 = GetUserInput();
	
	// Get mathematical operator
	char oper = GetMathOperation();

	// Get second number
	int n2 = GetUserInput();
	
	// Calculate result
	int nResult = CalculateResult(n1, oper, n2);

	// Print result
	PrintResult(nResult);
	
	return 0;
}

// functions implementation
int GetUserInput()
{
	int number;
	cout << "Enter input number: ";
	cin >> number;
	return number;
}

char GetMathOperation()
{
	char chOperator;
	cout << "Please eneter an operator (+,-,*,or /): ";
	cin >> chOperator;
	return chOperator;
}

int CalculateResult (int firstn, char choper, int secondn)
{
	if (choper=='+')
		return (firstn + secondn);
	if (choper=='-')
		return (firstn - secondn);
	if (choper=='*')
		return (firstn * secondn);
	if (choper=='/')
		return (firstn / secondn);
}

void PrintResult (int nResult)
{
	cout << "Your result is: " << nResult << endl;
}
