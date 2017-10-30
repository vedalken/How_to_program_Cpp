// main.cpp
// Determine what will print out
#include <iostream>
using std::endl;
using std::cout;

int main()
{
	// initialize variables
	int x = 9;
	int y = 11;
	
	if (x < 10)
	if (y > 10)
	cout << "*****" << endl; // belongs to inner if statement
	else // else belongs to inner if 
	cout << "#####" << endl;	
	cout << "€€€€€" << endl; // this will be printed outside else and if!

	return 0;	
}
