#include <iostream>

int main ()
{
	using namespace std;			// local use namespace std
	
	cout << "Enter a first number: ";
	int x;					// we need x starting here
	cin >> x;				// immediately initialize x

	cout << "Enter a second number: ";
	int y;
	cin >> y;

	cout << "The sum is: " << x + y << endl;
	return 0;
}
