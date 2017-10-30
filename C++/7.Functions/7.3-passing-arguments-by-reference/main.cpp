// main.cpp
// Function with pass by reference value.
#include <iostream>
using namespace std;

// add one to integer variable
void addOne( int &y ) {
	y++;
}

int main()
{
	int x = 5;
	cout << "x = " << x << endl;
	addOne( x );
	cout << "x = " << x << endl;

	return 0;	
}
