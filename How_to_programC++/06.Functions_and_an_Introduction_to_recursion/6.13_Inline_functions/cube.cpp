// cube.cpp
// Program calls cube inline function to calculate cube volume.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

// define inline function cube
// Every time function is called by program, compiler copies functions body
// instead of function call.
inline double cube( const double side ) {
	return (side * side * side); // calculate cube
}

int main() 
{
	double cubeSide; // cube sidem length
	cout << "Enter the side lenght of cube: ";
	cin >> cubeSide;
	
	// display cube side length and volume
	cout << "Volume of cube with side " << cubeSide << " is " << cube( cubeSide ) << endl;	
	
	return 0;
}
