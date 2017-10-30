#include <iostream>
using namespace std;

// function returns double it's value
int doubleNumber( int x )
{
	return (2*x);	
}

int main ()
{
	// evaluation expression
	// no problems with allocated memory value
	int x = 0;
	
	cout << "Enter integer value: ";
	cin >> x;

	// function call, it returns integer value
	cout << doubleNumber(x) << endl;
	
	return 0;
}
