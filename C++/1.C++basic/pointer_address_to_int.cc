#include <iostream>
using namespace std;

void foo( int* p );

int main ()
{
	int i = 0;

	cout << i << endl;
	
	// Pass address of variable i, 
	// with changing default value i=0
	foo(&i);
	cout << i << endl;

	return 0;
}

void foo( int* p )
{
	(*p)++;
	cout << *p << endl;
}
