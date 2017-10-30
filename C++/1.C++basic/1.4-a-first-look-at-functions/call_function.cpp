// Program prints some text within function
#include <iostream>

// Declaration of function DoPrint()
void DoPrint()
{
	using namespace std; // we need this when uses cout and endl

	cout << "In DoPrint() " << endl;
}

// Declare function main()
int main()
{
	using namespace std; // we need this when uses cout and endl
	
	cout << "Starting main() " << endl;
	DoPrint(); // This is a function call
	DoPrint();
	DoPrint();
	cout << "Ending main() " << endl;
	return 0;	
}
