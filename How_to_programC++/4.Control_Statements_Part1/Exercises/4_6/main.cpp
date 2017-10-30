// main.cpp
// Increment operator in multiplication and division.
#include <iostream>
using std::cout;
using std::endl;

// program execution begins with main
int main()
{
	int x;
	int product;
	
	// initilaize product and x to 5
	product = x = 5;
	// diplay initial values
	cout << "x=" << x << ", product=" << product << endl;
	// preincrement value
	// use x in product, than increment x
	product *= x++; // x = 5, product = 5, product = product * x = 25, x=6	
	cout << "x=" << x << ", product=" << product << endl;
	
	// postincrement value
	product = x = 5;
	// display initial values
	cout << "x=" << x << ", product=" << product << endl;
	// change values
	product *= ++x; // x = 6, product = 5, product = product * x = 30, x = 6
	cout << "x=" << x << ", product=" << product << endl;
	
	// reinitialize value
	float quotient;
	quotient = static_cast<float>( x = 5 );

	cout << "x=" << x << ", quotient=" << quotient << endl;
	// preincrement value first
	quotient /= ++x; // x=6, quotient=5.0, quotient = quotient / x = 5/6, x = 6

	cout << "x=" << x << ", quotient=" << quotient << endl;

	return 0;	
}
