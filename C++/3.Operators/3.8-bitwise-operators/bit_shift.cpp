#include <iostream>

int main ()
{
	using namespace std;
	
	unsigned int nValue = 5;	// 5 base 10 = 0101 base 2 
	nValue = nValue << 1;		// shift 1 bit left: 0101 -> 1010 base 2 = 10 base 10
	cout << nValue << endl;

	nValue = ~nValue;	// bitwise NOT 
	cout << "NOT: " << nValue << endl;

	return 0;
}
