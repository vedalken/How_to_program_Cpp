#include <iostream>

int add( int x, int y);

int main()
{
	using namespace std;

	// Linker will complain, but not compiler!
	// No function definition
	cout << "The sum of 3 and 4 is " << add(3,4) << endl;
	return 0;
}
