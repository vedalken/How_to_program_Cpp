// Program display variable location 
// in memory. There is no expression assigment
// to a variable.
// This is very dangerous use of unassigned variable!
// Diferent output depending on compiler.
// gcc automatically assing 0 to every unassigned variable.

#include <iostream>

int main ()
{
	// declare variable, with no expression assigment
	int x;

	// display mamory assigment location
	std::cout << x << std::endl;
	// gcc returns 0

	return 0;
}
