// main.cpp
// Display resursion depth.
#include <iostream>
#include "functions.h"
using std::cout;
using std::cin;

int main()
{
	cout << "Enter integer ( < 11): ";
	int number;
	cin >> number;

	factorial( number );

	return 0;	
}
