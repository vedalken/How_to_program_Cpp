// square.cpp
// Overloaded functions.
#include <iostream>
using namespace std;

// function prototype - function overloaded!
int 	square( int );
double	square( double );

int main()
{
	cout << square( 5 ); 
	cout << endl;
	cout << square( 5.23 );
	cout << endl;
	return 0;	
}

// Calculate square of integer and double number
int	square( int x ) { 
	cout << "Square of " << x << " is ";
	return x * x; 
}//destroy x

double square( double x ) { 
	cout << "Square of " << x << " is ";
	return x * x; 
}//destroy x

