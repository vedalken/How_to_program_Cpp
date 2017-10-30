#include <iostream>
#include <cstdlib>

int main()
{
	using namespace std;
	cout << 1 << endl;
	exit(EXIT_SUCCESS);	// terminate and return 0 to operating system

	// following statements never execute
	cout << 2 << endl;
	
	return 0;
}
