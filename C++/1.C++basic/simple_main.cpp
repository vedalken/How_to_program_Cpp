// To compile and link simpe_main.cpp and add.cpp
//	g++ -o simple_main simple_main.cpp add.cpp
//	run: ./simple_main
#include <iostream>
#include "add.h"	// this brings in the declaration for add()
			// copies the contents of add.h into the current file

// function is defined in add.cpp
// using header file, forward declaration is defined inside it
//int add(int x, int y); // forward declaration using function prototype 

int main()
{
	using namespace std;

	cout << "The sum 4 + 8 = " << add(4,8) << endl;
	return 0;
}
