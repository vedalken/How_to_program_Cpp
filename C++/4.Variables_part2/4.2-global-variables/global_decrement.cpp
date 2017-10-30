#include <iostream>

int nValue = 5; // global variable

int main()
{
	int nValue = 7;	// hides the global varible nValue
	std::cout << nValue++ 	<< std::endl;	// local increment
	std::cout << ::nValue-- << std::endl;	// global decrement

	return 0;
} // local variable nValue is destroyed!
