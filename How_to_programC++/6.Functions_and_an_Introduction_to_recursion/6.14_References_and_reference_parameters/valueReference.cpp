// valueReference.cpp
// Program test two function using call by value
// and call by reference. For larger programs, overhead of copy parameters
// list is not recommended, meanwhile pass-by-reference is performance
// recommended.
#include <iostream>
using std::cout;
using std::endl;

// function prototype with parameter pass by value and pass by reference
int	squareByValue( int );
void squareByRef( int & );

int main() 
{
	// declare two variables for testing different function behavior
	int x = 2; 
	int y = 4;

	// demonstrate call by value
	cout << "x = " << x << " before squareByValue\n";
	cout << "Value returned by squareByValue " <<  squareByValue( x ) << endl;
	cout << "x = " << x << " after squareByValue\n" << endl;

	// demonstrate call by reference
	cout << "y = " << y << " before squareByRef\n";
	squareByRef( y );
	cout << "y = " << y << " after squareByRef" << endl;

	return 0;	
}

// Calculate square of a number i.e. multiplies number by itself
// Argument is copied in parameter list. Parameters have local scope and
// does not change caller's number value.
int squareByValue( int number ) 
{
	return number *= number;
}// destroy number

// Calculate square of a number i.e. multiplies number by itself.
// Parameter call by reference - caller's value is changed!
void squareByRef( int &number ) 
{
	number *= number; // change caller's value
}
