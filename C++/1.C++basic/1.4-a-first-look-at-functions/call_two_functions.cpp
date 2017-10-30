// Program calls two functions, and print some message
#include <iostream>

// Declaration of function DoPrint2()
void DoPrint2()
{
	using namespace std;

	cout << "In DoPrint2() " << endl;
}

// Declaration of function DoPrint()
void DoPrint()
{
	using namespace std;	

	cout << "Starting DoPrint() " << endl;
	DoPrint2(); // This is function call DoPrint2()
	DoPrint2(); // This is function call DoPrint2()
	cout << "Ending DoPrint() " << endl;
}

// Declaration of main()
int main()
{
	using namespace std;

	cout << "Starting main() " << endl;
	DoPrint(); // This is a function call DoPrint
	cout << "Ending main() " << endl;

	return 0;	
} // end main function
