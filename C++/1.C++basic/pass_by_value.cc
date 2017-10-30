#include <iostream>
using namespace std;

void foo (int i)
{
	i++;
	cout << i << endl;
}

int main ()
{
	int i = 0;
	
	cout << i << endl;

	// Function call is made. Variable value i is copied.
	foo(i);
	
	// unchange local variable value i 
	cout << i << endl;

	return 0;
}
