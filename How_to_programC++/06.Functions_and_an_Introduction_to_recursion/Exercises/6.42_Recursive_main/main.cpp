// main.cpp
// Try to run recursive main function call.
#include <iostream>
using namespace std;

int main()
{
	static int count = 1; // count main call
	
	// If compiled, may prevent stack overflow
	if (count == 100)
		return 1;

	++count;
	cout << count << ", " << main() << endl;

	return 0;	
}
