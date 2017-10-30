#include <iostream>
using namespace std;

int operate( int a, int b)
{
	return (a*b);
}

float operate( float a, float b)
{
	return (a/b);
}

int main ()
{
	int x=5, y=2;
	float m=7.0, n=2.5;

	cout << operate (x,y) << "\n";
	cout << operate (m,n) << "\n";

	return 0;
}

