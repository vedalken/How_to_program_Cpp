#include <iostream>

using namespace std;

// function prototype
int addition (int a, int b);	//  forward declaration of function addition()

int main ()
{
	int z;

	z = addition (5,4);
	cout << "The result is: " << z << "\n";

	return 0;
}

int addition( int a, int b)
{
	return (a + b);

}
