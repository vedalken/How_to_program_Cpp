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
	using namespace std;	

	static int s_nValue = 1;	// fixed duration
	++s_nValue;
	cout << s_nValue << endl;

} // nValue is not destroyed!
