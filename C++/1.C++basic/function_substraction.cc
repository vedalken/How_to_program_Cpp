#include <iostream>

using namespace std;

int subtraction (int a, int b) {

	int r;
	r = a - b;
	return (r);
}

int main () 
{
	int x=7, y=5, z;
	z = subtraction (x,y);

	cout << "First result: " << z << "\n";
	cout << "Second result: " << subtraction (5,3) << "\n";
	cout << "Third result: " << subtraction (x,y) << "\n";
	z = 5 + subtraction (x,y);
	cout << "Fourth result: " << z << "\n";

	return 0;
}
