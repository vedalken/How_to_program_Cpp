#include <iostream>

int main()
{
	using namespace std;
	cout << "Enter a number: ";
	int nValue;
	cin >> nValue;

	if (nValue > 0)
	{// start of nested block
		cout << nValue << endl;
		cout << "Double this number: " << nValue*2 << endl;
	} // end of nested block

	return 0;
}
