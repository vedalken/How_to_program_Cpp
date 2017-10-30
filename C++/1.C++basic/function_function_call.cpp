#include <iostream>
using namespace std;

int add(int x, int y)
{
	return (x+y);
}

// Multiply function, which multiply two integers
int multiply(int z, int w)
{
	return (z*w);
}

int main()
{
	int x = 5;
	int y = 3;

	cout << add(4,5) << endl;	// Evaluates 4 + 5
	cout << add(x,y) << endl;	// Evaluates 5 + 3
	
	cout << add(7, multiply(x,y)) << endl; // Evaluates 7 + (5 * 3)
	return 0;
}
