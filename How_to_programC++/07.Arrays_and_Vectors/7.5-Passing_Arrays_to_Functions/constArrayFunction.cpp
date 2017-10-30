// constArrayFunction.cpp
// Function uses const integer array parameter,
// which cannot alter default values.
#include <iostream>
using std::cout;
using std::endl;

void tryToModifyArray( const int [] );
int main()
{
	int a[] = { 10, 20, 30 }; // initialize some array
	
	// try to change array values
	tryToModifyArray( a );
	cout << a[0] << ' ' << a[1] << ' ' << a[2] << endl;

	return 0;	
}

void tryToModifyArray( const int array[] )
{
	array[0] /= 2; // this gives compile error!
}
