#include <iostream>

int Min(int nX, int nY)
{
	return nX > nY ? nY : nX; // return smaller number
}

int Max(int nX, int nY)
{
	return nX > nY ? nX : nY; // return bigger number
}

int main()
{
	using namespace std;
	cout << "Enter a number: ";
	int nX;
	cin >> nX;

	cout << "Enter a second number: ";
	int nY;
	cin >> nY;
	
	// find smaller number
	cout << "Smaller number: " << Min(nX, nY) << endl;
	
	// find bigger number
	cout << "Bigger number: " << Max(nX, nY) << endl;

	return 0;
}
