#include <iostream>

int main()
{ // start outer block
	using namespace std;

	int x = 5;
	{ // start nested block
		int y = 7;
		cout << x << " + " << y << " = " << x+y << endl;
	} // destroy y here, x remains
	
	// y cannot be used here because it was destroyed
	
	return 0;
} // end outer block
