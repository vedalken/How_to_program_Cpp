#include <iostream>

int main()
{
	using namespace std;

	char chValue2 = 97;		// assign char with ASCII code 97

	// print code 97 from ascii 
	cout << chValue2 << endl;
	
	// convert character to integer
	cout << (int)chValue2 << endl;		// output 97, not 'a'

	return 0;
}
