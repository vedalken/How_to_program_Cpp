// main.cpp
// Preincrement and postincrement operator.
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int c;
	c = 5; // initialize variable
	
	// postincrement operator
	cout << c	<< endl; // c is 5
	cout << c++ << endl; // print 5 then posincrement
	cout << c	<< endl; // print incremented c

	cout << endl; // newline
	
	c = 5; // initialize variable
	cout << c	<< endl; // c is 5
	cout << ++c	<< endl; // preincrement c and then print
	cout << c	<< endl; // print 6

	return 0;	
}
