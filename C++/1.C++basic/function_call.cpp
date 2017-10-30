#include <iostream>
using namespace std; 	// we need this to include cout and endl

// Declaration of function DoPrint()
void DoPrint()
{
	cout << "In DoPrint()" << endl;
}

// Declaration of main
int main()
{
	cout << "Starting main()" << endl;	
	DoPrint();
	DoPrint();
	DoPrint();
	DoPrint();
	DoPrint();
	cout << "Ending main()" << endl;
	return 0;
}
