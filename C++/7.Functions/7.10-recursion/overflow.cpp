// overflow.cpp
// Recursive function call -> stack overflow occure!
#include <iostream>
using std::cout;
using std::endl;

// Recursive function prints number until stack overflow
// occure.
void countDown( int number ) {
	cout << number << endl;	
	countDown( number - 1 );
}

int main()
{
	// Begin recursive call with printing 10 until stack
	// overflow occure
	countDown( 10 ); 
	return 0;
}
