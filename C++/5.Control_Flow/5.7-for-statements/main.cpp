// main.cpp
// Program display's numbers from 1 to 10.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int i=0;
	for (; i<10; ) {
		cout << i << " ";
		++i;
	}

	cout << endl;
	cout << "Print ascending/desceding order of numbers" << endl;
	
	for (int iii=0, jjj=9; iii < 10; iii++, jjj--) {
		cout << iii << " " << jjj << endl;
	}
	

	return 0;
}
