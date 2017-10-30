// main.cpp
// Print * or + on evry odd or even line for ten lines.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int count = 1; // initialize count

	while (count <= 10)
	{
		// Display asterix and addition operator on every
		// odd and even line
		cout << (count % 2 ? "*****": "+++++") << endl;	
		++count;
	}

	return 0;	
}
