/*	Programs find out whether entered integers
	are equal or not.
*/
#include <iostream>
using namespace std;

// returns true if x and y are equal.
bool IsEqual(int x, int y)
{
		return (x==y);		// equality operator test equal
}

int main()
{
		cout << "Enter first integer: ";
		int x;
		cin >> x;

		cout << "Enter second integer: ";
		int y;
		cin >> y;

		bool bEqual = IsEqual(x,y);
		if (bEqual)
				cout << x << " and " << y << " are equal!" << endl;
		else
				cout << x << " and " << y << " are not equal!" << endl;

		return 0;
}
