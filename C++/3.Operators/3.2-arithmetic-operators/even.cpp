// Program figure out whether number is even or not
#include <iostream>

bool IsEven(int x);	// function prototype

int main()
{
	using namespace std;

	cout << "Enter an interger: ";
	int nNumber;
	cin >> nNumber;

	cout << "Binary answer: " << IsEven(nNumber) << endl;
	
	return 0;
}

// function definition
bool IsEven(int x)
{
	if ( x%2 == 0 )
			return true;	// return true, if it is even
	else
			return false;
}
