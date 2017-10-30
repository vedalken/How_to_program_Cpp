// count.cpp
// Recursive function call which prints numbers from 10 to 0.
#include <iostream>
using std::cout;
using std::endl;

// Recursive function prints number until stack overflow
// occure.
void countDown( int number ) {
	cout << number << endl;	// print current number
	if (number > 0)
		countDown( number - 1 );
}

int main()
{
	// Begin recursive call numbers from 10 to 0
	countDown( 10 ); 
	return 0;
}
