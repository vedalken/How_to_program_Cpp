// main.cpp
// do...while repetition statement
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int counter = 1;
	
	// do...while counts from 1 to 10
	do{
		cout << counter << " ";
		++counter;
	} while(counter <= 10);

	cout << endl;

	return 0;
}
