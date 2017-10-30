// break.cpp
// Program uses break statement to exit loop.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int count; // variable uses after for statement terminates

	for (count = 1; count <= 10; ++count) {
		if (count == 5) {// terminate loop when counter reach 5
			break;
		}
		cout << count << " ";
	}

	cout << "\nBreak out of loop at count = " << count << endl;

	return 0;
}
