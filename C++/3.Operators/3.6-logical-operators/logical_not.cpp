// Be aware, the program evaluates wrong statement
// as expected!
// Don't do this things!
#include <iostream>

int main ()
{
	using namespace std;
	
	int x = 5;
	int y = 6;
	
	if (! x == y )	// wont evaluate as true!
			cout << "true:  x not equal y" << endl;
	else
			cout << "false: x equals y" << endl;
	
	// or the same, but shorter
	int z = (! x == y )? true: false;
	cout << z << endl;

	return 0;	
}
