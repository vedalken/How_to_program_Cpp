#include <iostream>

void IncrementAndPrint();

int main()
{
	IncrementAndPrint();
	IncrementAndPrint();
	IncrementAndPrint();

	return 0;
}

void IncrementAndPrint()
{ // block scope
	using namespace std;	// local call

	int nValue = 1;	// auto is by default!
	++nValue;
	cout << nValue << endl;

} // end of block scope. nValue is destroyed!
