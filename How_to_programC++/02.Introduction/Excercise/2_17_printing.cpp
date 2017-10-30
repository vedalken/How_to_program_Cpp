// 2_17_printing.cpp
// Program prints numbers from 1 to 4 in three different ways
// using one statement with one stream insertion operator,
// using one statement with four stream insertion operator, and
// using four statements.
#include <iostream>

int main()
{
	std::cout << "1 2 3 4" << std::endl; // one stream insertion operator

	std::cout << "1 " << "2 " << 
				 "3 " << "4 " << std::endl; // four stream insertion operator
	
	// using four statements
	std::cout << "1 ";
	std::cout << "2 ";
	std::cout << "3 ";
	std::cout << "4 " << std::endl;
	
	return 0;
} // end main function
