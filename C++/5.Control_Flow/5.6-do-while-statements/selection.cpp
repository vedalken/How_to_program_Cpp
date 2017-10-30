// selection.cpp
// Selection program uses do...while loop.
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int selection;

	// Display message until right number is entered
	do
	{
		cout << "Please make selection: "	<< endl;
		cout << "(1) Addition" 				<< endl;
		cout << "(2) Subtraction" 			<< endl;
		cout << "(3) Multiplication"		<< endl;
		cout << "(4) Division"				<< endl;
		// read input by user
		cin >> selection;
	// Loop while correct number is read
	} while( selection != 1 && selection != 2 && 
			selection != 3 && selection != 4); 

	// do something with selection variable

	return 0;
}
