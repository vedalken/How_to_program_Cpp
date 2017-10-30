#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int printedNumbers = 0;

	for (int i=0; i<100; ++i) 
	{
		if ((i%3==0) && (i%4==0)) 
		{
			cout << i << " ";
			++printedNumbers;
		}
	}
	cout << "\nNumbers found: " << printedNumbers << endl;

	return 0;
}
