#include <iostream>

int main()
{
	using namespace std;

	int x = 5;
	cout << x << endl;
	
	// Compiler makes a temporary copy of x
	// which still has the original value of 5.
	int y = x++;
	cout << y << ", " << x << endl;

	// The value of x is incremented, and then 
	// evaluates the temporary copy of x.
	int z = ++x;
	cout << z << ", " << x << endl;
	
	int m = 5, n = 5;
	cout << m   << " " << n   << endl;	// 5, 5
	cout << ++m << " " << --n << endl;	// prefix: 6, 4
	cout << m   << " " << n   << endl;	// 6, 4
	cout << m++ << " " << n-- << endl;	// postfix: 6, 4
	cout << m   << " " << n   << endl;	// 7, 3
	
	return 0;
}

