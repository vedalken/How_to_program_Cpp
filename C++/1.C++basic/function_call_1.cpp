#include <iostream>
using namespace std;

// Declaration of function DoPrint2()
void DoPrint2()
{
	cout << "\t\tIn DoPrint2()" << endl;
}

// Declaration of function DoPrint()
void DoPrint()
{
	cout << "\tStarting DoPrint()" << endl;
	DoPrint2();	// This is a function call to DoPrint2()
	DoPrint2();	// This is a function call to DoPrint2()
	cout << "\tEnding DoPrint()" << endl;

}

// Declaration of main()
int main()
{
	cout << "Starting main()" << endl;
	DoPrint();	// This is a function call to DoPrint()
	cout << "Ending main()" << endl;
	return 0;
}
