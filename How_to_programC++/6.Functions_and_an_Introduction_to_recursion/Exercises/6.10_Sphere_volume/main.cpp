// main.cpp
// Calculate sphere volume with inline function call.
// Inline function eliminates function call overhead. Compiler
// replaces body of inlined function by function call.
#include <iostream>
#include <cmath>
using std::cout; // iostream
using std::endl;
using std::pow; // cmath

// Calculate sphere volume wiht radius r
// V = ( 4/3 ) * pi * r^3
//
inline void sphereVolume( double radius ) { 
	//return ( 4.0/3.0 * 3.1415926 * pow( radius, 3 ) );
	register double V; // volume 
	V = 4.0/3.0 * 3.1415926 * pow( radius, 3 );
}

int main()
{
	for (register long long i=0; i < 1000000000; ++i) {
		sphereVolume( i );
	}

	return 0;	
}
