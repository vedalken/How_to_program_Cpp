//Example of passing value to a pointer.
//
#include <iostream>
using namespace std;

void  print ( const char* p );
void triple ( int& number );

int main ()
{
	const char* s = "The world is great!"; 
	int n = 5;

	// function call to print out all characters of the string
	print (s);
	
	cout << "n: " << n << endl;
	triple( n );
	cout << "Changed n by reference: " << n << endl;

	return 0;
}

void print( const char* p )
{
	for (; *p != '\0'; p++)		
		// print a character of a string array.
		cout << *p;	
	cout << endl;
}

void triple( int& number )
{
	number *= 3;
}
