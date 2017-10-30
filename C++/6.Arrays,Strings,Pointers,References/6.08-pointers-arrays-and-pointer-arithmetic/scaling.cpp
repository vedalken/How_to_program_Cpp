// scaling.cpp
// Compile scales when doing pointer arithmetic
// operations.
#include <iostream>
using namespace std;
int main()
{
	short nValue = 6;
	short * nPtr = &nValue;
	
	cout << nValue
		<< "\n" << nPtr
		<< "\n" << nPtr + 1
		<< "\n" << nPtr + 2
		<< "\n" << nPtr + 3 << endl;
	return 0;	
}
