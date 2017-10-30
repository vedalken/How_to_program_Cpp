#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter a number: ";
	int nX;
	cin >> nX;
	
	if (nX > 10)
	{
		cout << "You entered " << nX << endl;
		cout << nX << " is greater than 10." << endl;
	}
	else if (nX < 5)
	{
		cout << "You entered " << nX << endl;
		cout << nX << " is smaller than 5." << endl;
	}
	else
	{
		cout << "You entered " << nX << endl;
		cout << nX << " is between 5 and 10." << endl;
	}

	return 0;
}
